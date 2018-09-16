#ifndef ATTRPARSER_H
#define ATTRPARSER_H
#include <regex>

namespace cxx_challenges
{
  struct Tag;
  class AttrParser
  {
  private:
    Tag *node;
    std::regex expr;
    std::smatch sm;
    Tag *head_node;
    std::string head;
    Tag* Get(const std::string& name);

  public:
    AttrParser();
    ~AttrParser();
    void SetExpr(const std::string& _expr);
    void SetLine(const std::string& str);
    void Reset();
    std::string GetValue(const std::string& input);
  };
}

#endif // ATTRPARSER
