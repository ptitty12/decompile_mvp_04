#include "translator/symbols.h"

#include <cstdlib>
#include <sstream>

namespace mvp::xlat {

namespace {

std::string trim(const std::string& s) {
  std::size_t a = s.find_first_not_of(" \t\r");
  std::size_t b = s.find_last_not_of(" \t\r");
  return a == std::string::npos ? std::string() : s.substr(a, b - a + 1);
}

}  // namespace

SymbolTable SymbolTable::parse(const std::string& text, std::vector<std::string>* errors) {
  SymbolTable t;
  std::istringstream in(text);
  std::string line;
  int lineno = 0;
  while (std::getline(in, line)) {
    ++lineno;
    std::string l = trim(line);
    if (l.empty() || l[0] == '#') continue;
    auto eq = l.find(" = ");
    auto colon = eq == std::string::npos ? std::string::npos : l.find(":0x", eq);
    auto semi = colon == std::string::npos ? std::string::npos : l.find(';', colon);
    if (eq == std::string::npos || colon == std::string::npos || semi == std::string::npos) {
      if (errors) errors->push_back("line " + std::to_string(lineno) + ": cannot parse");
      continue;
    }
    Symbol s;
    s.name = l.substr(0, eq);
    s.section = l.substr(eq + 3, colon - (eq + 3));
    s.address = static_cast<u32>(std::strtoul(l.c_str() + colon + 3, nullptr, 16));
    std::string attrs = semi + 1 < l.size() ? l.substr(semi + 1) : "";
    std::istringstream words(attrs);
    std::string w;
    while (words >> w) {
      if (w == "//") continue;
      if (w.rfind("type:", 0) == 0) {
        std::string ty = w.substr(5);
        s.type = ty == "function" ? Symbol::Type::Function
                 : ty == "label"  ? Symbol::Type::Label
                 : ty == "object" ? Symbol::Type::Object
                                  : Symbol::Type::Unknown;
      } else if (w.rfind("size:", 0) == 0) {
        s.size = static_cast<u32>(std::strtoul(w.c_str() + 5, nullptr, 0));
      } else if (w == "scope:local") {
        s.local = true;
      } else if (w.rfind("data:", 0) == 0) {
        s.data = true;
      }
    }
    t.symbols_.push_back(std::move(s));
  }
  for (const Symbol& s : t.symbols_) {
    if (s.type == Symbol::Type::Function) {
      auto [it, inserted] = t.functions_.emplace(s.address, &s);
      if (!inserted && errors) errors->push_back("two functions at the same address: " + s.name);
    }
    if (s.type == Symbol::Type::Object && s.name.rfind("jumptable_", 0) == 0) t.jump_tables_.emplace(s.address, &s);
    if (s.type == Symbol::Type::Object) t.objects_.emplace(s.address, &s);
    if (s.type == Symbol::Type::Label && is_code_section(s.section) && !s.data) t.code_labels_.emplace(s.address, &s);
    t.by_name_.emplace(s.name, &s);
  }
  return t;
}

const Symbol* SymbolTable::function_at(u32 start) const {
  auto it = functions_.find(start);
  return it == functions_.end() ? nullptr : it->second;
}

const Symbol* SymbolTable::function_containing(u32 addr) const {
  auto it = functions_.upper_bound(addr);
  if (it == functions_.begin()) return nullptr;
  --it;
  const Symbol* s = it->second;
  return addr < s->address + s->size ? s : nullptr;
}

const Symbol* SymbolTable::object_at(u32 addr) const {
  auto it = objects_.find(addr);
  return it == objects_.end() ? nullptr : it->second;
}

const Symbol* SymbolTable::code_label_at(u32 addr) const {
  auto it = code_labels_.find(addr);
  return it == code_labels_.end() ? nullptr : it->second;
}

const Symbol* SymbolTable::find(const std::string& name) const {
  auto it = by_name_.find(name);
  return it == by_name_.end() ? nullptr : it->second;
}

}  // namespace mvp::xlat
