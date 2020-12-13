#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());

    std::transform(
       people.begin(), people.end(), ret_v.begin(), [](Human i) 
       { 
         if(i.isMonster())
          return 'n';
         else
          return 'y';
      });

    std::reverse(ret_v.begin(), ret_v.end());

    return ret_v;
}
