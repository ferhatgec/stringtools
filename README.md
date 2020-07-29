# StringTools
## Single header String tool library.

```cpp
std::string betweenstr("#Hello developers!?");
std::cout << "String between # and ? : " << stringtools::GetBetweenString(betweenstr, "#", "?") << "\n";
std::cout << "L character count : " << stringtools::Count(betweenstr, 'l') << "\n"; // 3
```

##### StringTools licensed under the terms of MIT License.
