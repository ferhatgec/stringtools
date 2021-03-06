/*# MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef STRING_TOOLS_HPP
#define STRING_TOOLS_HPP

#include <iostream>
#include <string>

namespace stringtools {
    static std::string EraseAllSubString(std::string &mainString, const std::string &erase) {
        std::size_t pos = std::string::npos;

        while((pos = mainString.find(erase)) != std::string::npos) {
            mainString.erase(pos, erase.length());
        }

        return mainString;
    }

    static void replaceAll(std::string &str, const std::string &from, const std::string &to) {
        if(from.empty()) {
            return;
        }

        std::size_t start_pos = 0;

        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    }

    static bool replace(std::string &str, const std::string &from, const std::string &to) {
        std::size_t start_pos = str.find(from);

        if (start_pos == std::string::npos) {
            return false;
        }

        str.replace(start_pos, from.length(), to);

        return true;
    }

    static int Count(std::string s, char ch) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ch) {
                count++;
            }
        }

        return count;
    }

    static int Counter(const char *str, int type) { // 1 = Vowel, 2 = Consonants, 3 = Numbers, 4 = Special characters
        int v = 0, c = 0, n = 0, s = 0;

        for(int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                ++v;
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                ++c;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                ++n;
            }
            else {
                ++s;
            }
        }

        switch(type) {
            case 1: {
                return v;
            }

            case 2: {
                return c;
            }

            case 3: {
                return n;
            }

            case 4: {
                return s;
            }

            default: {
                return v;
            }
        }

        return 0; // Unrequired
    }

    // Return as string
    static std::string GetBetweenString(std::string oStr, std::string sStr1, std::string sStr2) {
        int start = oStr.find(sStr1);

        if (start >= 0) {
            std::string tstr = oStr.substr(start + sStr1.length());

            int stop = tstr.find(sStr2);

            if (stop > 1) {
                return oStr.substr(start + sStr1.length(), stop);
            } else {
                return "error";
            }
        }
        else {
            return "error";
        }
    }

    static void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {
        rStr = stringtools::GetBetweenString(oStr, sStr1, sStr1);
    }

    // get first between string from 0.... position.
    static std::string Between(const std::string &s, const std::string &start_delim, const std::string &stop_delim) {
        unsigned first_delim_pos = s.find(start_delim);
        unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
        unsigned last_delim_pos = s.find_first_of(stop_delim, end_pos_of_first_delim);

        return s.substr(end_pos_of_first_delim,
                        last_delim_pos - end_pos_of_first_delim);
    }

    static std::string Add(std::string a, std::string b) {
        std::string temp = "";

        int carry = 0;

        while(a.length() < b.length()) {
            a = "0" + a;
        }

        while(b.length() < a.length()) {
            b = "0" + b;
        }

        for(int i = a.length() - 1; i >= 0; i--) {
            char val = static_cast<char>(((a[i] - 48) + (b[i] - 48)) + 48 + carry);

            if(val > 57) {
                carry = 1;
                val -= 10;
            }
            else {
                carry = 0;
            }
            temp = val + temp;
        }

        if(carry == 1) {
            temp = "1" + temp;
        }

        while(temp[0] == '0' && temp.length() > 1) {
            temp = temp.substr(1);
        }

        return temp;
    }

    static int Compare(const char *str_1, const char *str_2) {
        const unsigned char *unsigned_str_1 = (const unsigned char *) str_1;
        const unsigned char *unsigned_str_2 = (const unsigned char *) str_2;

        while (*unsigned_str_1 == *unsigned_str_2 &&
               *unsigned_str_1 != '\0') {

            unsigned_str_1++;
            unsigned_str_2++;
        }

        return (*unsigned_str_1 > *unsigned_str_2) - (*unsigned_str_1 < *unsigned_str_2);
    }

    static inline std::string &ltrim(std::string &s, const char *t = " \t\n\r\f\v") {
        return s.erase(0, s.find_first_not_of(t));
    }

    static inline std::string &rtrim(std::string &s, const char *t = " \t\n\r\f\v") {
        return s.erase(s.find_last_not_of(t) + 1);
    }

    static inline std::string &trim(std::string &s, const char *t = " \t\n\r\f\v") {
        trim(s);
        ltrim(s);

        return s;
    }

    static bool Find(std::string &data, std::string substring) {
        std::size_t check = data.find(substring);

        if(check != std::string::npos) {
            return true; // Found
        }

        return false;
    }

    /* Try KMP algorithm for pattern searching to replace within it */
    static int CountSub(const std::string &str, const std::string &sub) {
        if(sub.length() == 0) return 0;

        int count = 0;

        for(size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length()))
            ++count;

        return count;
    }

    static std::string EraseSub(std::string &mainString, const std::string &erase) {
        std::size_t pos = std::string::npos;

        if((pos = mainString.find(erase)) != std::string::npos)
            mainString.erase(pos, erase.length());

        return mainString;
    }

    static std::string GetFirstArg(std::string str) {
        std::string word = "";

        if(!str.find(" ")) return str;

        for(auto x : str) {
            if (x == ' ') {
                break;
            }

            word = word + x;
        }

        return word;
    }
}

#endif // STRING_TOOLS_HPP
