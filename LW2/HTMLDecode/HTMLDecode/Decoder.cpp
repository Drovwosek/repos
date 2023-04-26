#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<string, char> HTML_ENTITY_MAP = {
    {"&quot;", '\"'},
    {"&apos;", '\''},
    {"&lt;", '<'},
    {"&gt;", '>'},
    {"&amp;", '&'}
};

const char AMP = '&';

void CheckSubstring(string const& html, unsigned& pos, char tmpCh)
{
    for (auto& decodeEntity : HTML_ENTITY_MAP)
    {
        if (html.substr(pos, decodeEntity.first.length()) == decodeEntity.first)
        {
            tmpCh = decodeEntity.second;
            pos += decodeEntity.first.length() - 1;
            break;
        }
    }
};

string HTMLDecode(string const& html)
{
    string decodedStr;

    for (unsigned i = 0; i < html.length(); i++)
    {
        if (html[i] == AMP)
        {
            CheckSubstring(html, i, AMP); //от i до i + 
            decodedStr += AMP;
        }
        else
        {
            decodedStr += html[i];
        }
    }

    return decodedStr;
};
