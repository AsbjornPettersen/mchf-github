#include <stdio.h>
#include <vector>

class argstab
{
  std::vector<std::string> tab;
public:
  bool get_arguments(const int argc, char *argv[]);
  void dump() const
  {
    unsigned int i = 0;
    for (auto it = tab.cbegin(); it != tab.cend(); ++it) 
      {       
	std::string c = *it;
	printf ("%d %s\n",i,c.c_str());
      }
  };
  char get_ch0() const
  {
    auto it = tab.cbegin();
    std::string c = *it;
    return *c.c_str();
  };
  std::string get_param(const std::string firstoption) const
  {
    std::string param;
    for (auto it = tab.cbegin(); it != tab.cend(); ++it) 
      {       
	std::string c = *it;
	if (c == firstoption)
	  {
	    it++;
	    if (it == tab.cend())
	      return param;
	    param = *it;
	    return param;
	  }
      }
    return param;
  };
};