#include <string.h>
#include <iostream>

bool isPolindrome(const char* source)
{
    const size_t len_source = strlen(source);
    
    const int half_len_source = static_cast<int>(len_source/2);
    
    for(int i=0; i<half_len_source; i++)
    {        
        
        if(source[i] != source[len_source-1-i])
        {
            return false;
        }
    
    }
    return true;
     
}

int main()
{
   
   std::cout<<isPolindrome("cdabbadc");
   
   return 0;
}

