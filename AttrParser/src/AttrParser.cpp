#include "AttrParser.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace cxx_challenges
{
  struct Tag
  {
    Tag* next;
    string name;
    map<string, string> attr;
    Tag() : next(0) {}
    Tag(const string& _name)
        : name(_name), 
          next(0) {
    }
    void SetAttr(
            const string& _attr,
            const string& _attr_val){
        attr.emplace(_attr, _attr_val);
    }
    string GetVal(const string& _attr){
        map<string, string>::iterator it = attr.find(_attr);
        return ( it != attr.end())
                ? it->second : string();
    }
  };

  AttrParser::AttrParser()
  {
    expr = string("([\\^%$,.|!?*+()\\w]+)|((\\w+) \\= \"(\\w+)\")+");
    head_node = new Tag();
    node = head_node;
  }
  AttrParser::~AttrParser()
  {
    if(node)
      delete node;
    if(head_node)
      delete head_node;
  }
  void AttrParser::SetExpr(const string& _expr)
  {
    expr = _expr;
  }

  void AttrParser::SetLine(const string& str)
  {
    stringstream ss;
    string exp = str.c_str();
    if (regex_search(exp, sm, regex("(^</)(\\w+)(>?)"))){
        string tag(sm[2]);
        unsigned int tagl(tag.length());
        string::size_type foundpos = head.find(tag);
        if ( foundpos != string::npos ){
            if (foundpos){
                foundpos--;
                tagl++;
            }
            if ((!foundpos) && (head.size() > tagl))
                tagl++;
            head.erase(head.begin() +
                       foundpos, head.begin() + foundpos + tagl);
        }
        return;
    }

    while(regex_search(exp, sm, expr)){
        ss << sm.str() << endl;
        exp=  sm.suffix();
    }

    ss >> exp;
    head += (head.size())?'.'+exp : exp;
    Tag * tag = new Tag(head);
    string attr, attr_val;
    while(ss >> attr >> attr_val){
        tag->SetAttr(attr, attr_val);
    }

    node->next = tag;
    node = node->next;
  }

  void AttrParser::Reset()
  {
    node = head_node->next;

    // while( node && node->next)
    // {
    //   printf("Node Name: %s - %s - %s -> ", 
    //     node->name.c_str(), node->attr.c_str(), node->attr_val.c_str());

    //   node = node->next;
    // }

    // if(node)
    //   printf("Node Name: %s - %s - %s \n", 
    //     node->name.c_str(), node->attr.c_str(), node->attr_val.c_str());
  }

  Tag* AttrParser::Get(const string& name)
  {
    node = head_node->next;
    while( node && node->next)
    {
      if(node->name == name)
        return node;

      node = node->next;
    }

    if(node->name == name)
        return node;

    return NULL;
  }

  string AttrParser::GetValue(const string& input)
  {
    vector<string> tags;
    string exp(input);
    if (regex_search(exp, sm, regex("(\\w.+|\\w+)(~)(\\w+)")))
    {
        Tag* tag = Get(string(sm[1]));
        if(!tag)
          return string("Not Found!");

        string attr(tag->GetVal(string(sm[3])));
        return attr.size() ? attr : string("Not Found!");
    }

    return string("Not Found!");
  }
}
