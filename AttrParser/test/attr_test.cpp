#include <catch.hpp>
#include "AttrParser.h"
using namespace cxx_challenges;

TEST_CASE( "Attribute parser test1 (pass)", "[single-file]" ) {
    AttrParser attrParser;
    attrParser.SetLine("<tag1 value = \"HelloWorld\">");
    attrParser.SetLine("<tag2 name = \"Name1\">");

    SECTION( "Check tag attributes")
    {
      REQUIRE( attrParser.GetValue("tag1.tag2~name") == "Name1" );
      REQUIRE( attrParser.GetValue("tag1~value") == "HelloWorld" );
    }
}

TEST_CASE( "Attribute parser test2 (pass)", "[single-file]" ) {
    AttrParser attrParser;
    attrParser.SetLine("<a value = \"GoodVal\">");
    attrParser.SetLine("<b value = \"BadVal\" size = \"10\">");
    attrParser.SetLine("<c height = \"auto\">");
    attrParser.SetLine("<d size = \"3\">");
    attrParser.SetLine("<e strength = \"200%\">");
    attrParser.SetLine("<f a1 = \"1\" a2 = \"2\" a3 = \"3\">");

    SECTION( "Check tag attributes")
    {
      REQUIRE( attrParser.GetValue("a.b.c.d.e.f~a1") == "1" );
      REQUIRE( attrParser.GetValue("a.b.f~a1") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.b~size") == "10" );
      REQUIRE( attrParser.GetValue("a.b.c.d.e.f~a2") == "2" );
      REQUIRE( attrParser.GetValue("a.b.c.d.e.f~a3") == "3" );
      REQUIRE( attrParser.GetValue("a.c~height") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.b.d.e~strength") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.b.c.d.e~strength") == "200%" );
      REQUIRE( attrParser.GetValue("d~sze") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.b.c.d~size") == "3" );
    }
}

TEST_CASE( "Attribute parser test3 (pass)", "[single-file]" ) {
    AttrParser attrParser;
    attrParser.SetLine("<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">");
    attrParser.SetLine("</tag1>");
    attrParser.SetLine("<tag2 v4 = \"v2\" name = \"Tag2\">");
    attrParser.SetLine("<tag3 v1 = \"Hello\" v2 = \"World!\">");
    attrParser.SetLine("</tag3>");
    attrParser.SetLine("<tag4 v1 = \"Hello\" v2 = \"Universe!\">");
    attrParser.SetLine("</tag4>");
    attrParser.SetLine("</tag2>");
    attrParser.SetLine("<tag5>");
    attrParser.SetLine("<tag7 new_val = \"New\">");
    attrParser.SetLine("</tag7>");
    attrParser.SetLine("</tag5>");
    attrParser.SetLine("<tag6>");
    attrParser.SetLine("<tag8 intval = \"34\" floatval = \"9.845\">");
    attrParser.SetLine("<ntag nv = \"4$\">");
    attrParser.SetLine("<nvtag nv = \"6$\">");
    attrParser.SetLine("</nvtag>");
    attrParser.SetLine("</nvtag>");
    attrParser.SetLine("</tag8>");
    attrParser.SetLine("</tag6>");

    SECTION( "Check tag attributes")
    {
      REQUIRE( attrParser.GetValue("tag1~v1") == "123" );
      REQUIRE( attrParser.GetValue("tag1~v2") == "43.4" );
      REQUIRE( attrParser.GetValue("tag1~v3") == "hello" );
      REQUIRE( attrParser.GetValue("tag4~v2") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag2.tag4~v1") == "Hello" );
      REQUIRE( attrParser.GetValue("tag2.tag4~v2") == "Universe!" );
      REQUIRE( attrParser.GetValue("tag2.tag3~v2") == "World!" );
      REQUIRE( attrParser.GetValue("tag5.tag7~new_val") == "New" );
      REQUIRE( attrParser.GetValue("tag5~new_val") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag7~new_val") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag6.tag8~intval") == "34" );
      REQUIRE( attrParser.GetValue("tag6.tag8~floatval") == "9.845" );
      REQUIRE( attrParser.GetValue("tag6.tag8~val") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag8~intval") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag6.tag8.ntag~nv") == "4$" );
      REQUIRE( attrParser.GetValue("tag6.tag8.ntag.nvtag~nv") == "6$" );
      REQUIRE( attrParser.GetValue("tag6.tag8.nvtag~nv") == "Not Found!" );
      REQUIRE( attrParser.GetValue("randomtag~nv") == "Not Found!" );
      REQUIRE( attrParser.GetValue("tag283.tag21.den~jef") == "Not Found!" );
    }
}

TEST_CASE( "Attribute parser test4 (pass)", "[single-file]" ) {
    AttrParser attrParser;
    attrParser.SetLine("<a value = \"GoodVal\">");
    attrParser.SetLine("<b value = \"BadVal\" size = \"10\">");
    attrParser.SetLine("</b>");
    attrParser.SetLine("<c height = \"auto\">");
    attrParser.SetLine("<d size = \"3\">");
    attrParser.SetLine("<e strength = \"2\">");
    attrParser.SetLine("</e>");
    attrParser.SetLine("</d>");
    attrParser.SetLine("</c>");
    attrParser.SetLine("</a>");

    SECTION( "Check tag attributes")
    {
      REQUIRE( attrParser.GetValue("a~value") == "GoodVal" );
      REQUIRE( attrParser.GetValue("b~value") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.b~size") == "10" );
      REQUIRE( attrParser.GetValue("a.b~value") == "BadVal" );
      REQUIRE( attrParser.GetValue("a.b.c~height") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.c~height") == "auto" );
      REQUIRE( attrParser.GetValue("a.d.e~strength") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.c.d.e~strength") == "2" );
      REQUIRE( attrParser.GetValue("d~sze") == "Not Found!" );
      REQUIRE( attrParser.GetValue("a.c.d~size") == "3" );
    }
}