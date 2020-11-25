#include "../_freecplus.h"

int main()
{
  CFile File;

  if (File.Open("girl.xml","r")==false)
  {
    printf("File.Open(%s) failed.\n","girl.xml"); return -1;
  }

  char strBuffer[1024];

  while (true)
  {
    memset(strBuffer,0,sizeof(strBuffer));
    if (File.FFGETS(strBuffer,1000,"</row>")==false) break;

    printf("=%s=\n",strBuffer);
  }
}

