#include <stdio.h>
#include "StudentList.h"

struct list_struct* get_user_list(void){
  //nhap vao so phan tu
  printf("Nhap vao so luong sinh vien cua lop:");
  int student_number;
  scanf("%d", &student_number);
  struct list_struct list;
  list.list_start = NULL;
  list.list_end = NULL;
  struct student_struct* student_pointer;
  for(int i = 0; i < student_number; i++){
    student_pointer = (struct student_struct*) malloc(sizeof(struct student_struct));
    printf("Nhap vao thong tin sinh vien thu %d:\n", student_number + 1);
    printf("Ten sinh vien: ");
    fgets(&student_pointer->name, 56, stdin);
    printf("Lop sinh vien: ");
    scanf(&student_pointer->class, 28, stdin);
    add_elem_to_list(&list, student_pointer);
  }
}

int add_elem_to_list(struct list_struct* L, struct student_struct* E){
  if(L == NULL || E == NULL)  return -1;

  //list is empty
  if(L->list_start == NULL){
    L->list_start = E;
    E->last_node = L->list_end;
    L->list_end = E;
    L->list_end->next_node = NULL;
    return 0;
  }

  //list not empty insert elem to tail
  E->last_node = L->list_end;
  L->list_end->next_node = E;
  L->list_end = E;
  L->list_end->next_node = NULL;
  return 0;
}

int selection_sort_list_ascent(struct list_struct* L){
  int result;
  struct student_struct* tmp_node = L->list_start, * min_node = L->list_start;
  while(tmp_node != NULL){
    while (min_node != NULL) {
      result = strncmp(min_node->name, min_node->next_node->name, 56);
      //next_node is smaller than min_node
      if(result > 0){
        //switch content

      }
    }
  }
}

int elem_swap(struct student_struct* elem1, struct student_struct* elem2){
  struct student_struct* last1, *last2, *next1, next2;


  //save last node and next node of elem1
  last1 = elem1->last_node;
  next1 = elem1->next_node;
  last2 = elem2->last_node;
  next2 = elem2->next_node;

  //give elem2 position in list of elem1
  elem1->last_node->next_node = elem2;
  elem2->
}
