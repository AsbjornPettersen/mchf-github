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
