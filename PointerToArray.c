#include <stdio.h>
#include "StudentList.h"

int main(void){
  struct list_struct* list;
  printf("Chon chuong trinh: \n");
  printf("1.Student List\n");
  printf("2.Matrix\n");
  printf("\nChon: ");
  int user_select;
  scanf("%d", &user_select);
  switch (user_select) {
    case 1:
      list = get_user_list();
      selection_sort_list_ascent(list);
      list_print(list);
      break;
    case 2:
      printf("chua co du lieu\n");
      break;
    default:
      printf("Error: command not recognized");
      break;
  }
  return 0;
}
