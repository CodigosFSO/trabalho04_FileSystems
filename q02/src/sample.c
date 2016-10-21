#include <dirent.h> 
#include <stdio.h> 

// int main(void)
// {
//   DIR *d;
//   struct dirent *dir;
//   d = opendir("/home/makrau/Área de Trabalho/snx_install.sh");
//   if (d)
//   {
//     while ((dir = readdir(d)) != NULL)
//     {
//       printf("%s\n", dir->d_name);
//     }

//     closedir(d);
//   }
//   else {
//     perror("");
//   }

//   return(0);
// }