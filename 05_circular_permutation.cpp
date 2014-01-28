#include <string.h>
#include <iostream>

bool isCircular (const char* source, const char* circular)
{
    const size_t len_source = strlen(source);
    const size_t len_circular = strlen(circular);
    
    if(len_source != len_circular)
    {
        return false;
    }
      
    char* double_source = static_cast<char*>(malloc(len_source + 1 + len_source));
    
    strcpy(double_source, source);
    strcat(double_source, source);
    
  
    if(strstr(double_source, circular))
    {
        return true;
    } 
    else
    {
        return false;
    }
}

int main()
{
   
   std::cout<<isCircular("abcde", "cdeab");
   
   return 0;
}

