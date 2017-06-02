#include "./argstab.h"

bool argstab::get_arguments(const int argc, char *argv[])
{
  for (int i=1; i < argc; i++)
    {
      tab.push_back(argv[i]);
    }
  if (tab.size() > 0)
    return true;
  return false;
}

bool argstab::get_flag(const std::string &str) const
{
  for (auto it = tab.cbegin(); it != tab.cend(); ++it) 
    {       
      std::string c = *it;
      if (c == str)
	{
	  return true;
	}
    }
  return false;
}

std::string argstab::get_param(const std::string firstoption) const
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
}

bool argstab::get_param_uint(const std::string firstoption, unsigned int &val) const
{
  std::string c = get_param(firstoption);
  if (c.empty())
    return false;
  val = (unsigned int) std::atoi(c.c_str());
  return true;
}
