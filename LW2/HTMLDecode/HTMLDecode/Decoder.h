#pragma once
#include <iostream>
#include <string>
#include <map>

const std::map<std::string, char> HTML_ENTITY_MAP = {
    {"&quot;", '\"'},
    {"&apos;", '\''},
    {"&lt;", '<'},
    {"&gt;", '>'},
    {"&amp;", '&'}
};

const char AMP = '&';

std::string HTMLDecode(std::string const& html);
