#include <stdio.h>
#include "StudentList.h"
#include <stdlib.h>
#include <string.h>

struct list_struct* get_user_list(void){
  //nhap vao so phan tu
  printf("Nhap vao so luong sinh vien cua lop:");
  int student_number;
  scanf("%d", &student_number);
  struct list_struct* list =(struct list_struct*) malloc(sizeof(struct list_struct));
  list->list_start = NULL;
  list->list_end = NULL;
  struct student_struct* student_pointer;
  for(int i = 0; i < student_number; i++){
    student_pointer = (struct student_struct*) malloc(sizeof(struct student_struct));
    printf("Nhap vao thong tin sinh vien thu %d:\n", i + 1);
    printf("Ten sinh vien: ");
    scanf("%s", student_pointer->name);
    printf("Lop sinh vien: ");
    scanf("%s", student_pointer->class);
    add_elem_to_list(list, student_pointer);
  }
  return list;
}

int add_elem_to_list(struct list_struct* L, struct student_struct* E){
  if(L == NULL || E == NULL)  return -1;

  //list is empty
  if(L->list_start == NULL){
    L->list_start = E;
    E->last_node = NULL;
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
  struct student_struct* tmp_node = L->list_start, * min_node = L->list_start, *select_node = L->list_start;
  while(select_node != NULL){
    min_node = select_node;
    tmp_node = select_node;
    while ((tmp_node = tmp_node->next_node) != NULL) {
      result = strncmp(min_node->name, tmp_node->name, 56);
      //tmp_node is smaller than min_node
      if(result > 0){
        min_node = tmp_node;
      }
    }
    if(select_node->last_node == NULL)
      L->list_start = min_node;
    if(min_node->next_node == NULL)
      L->list_end = select_node;
    elem_swap(select_node, min_node);
    select_node = select_node->next_node;
  }
}

int elem_swap(struct student_struct* elem1, struct student_struct* elem2){
  if(elem1 == NULL || elem2 == NULL) return -1;
  struct student_struct* last1, *last2, *next1, *next2;

  //save last node and next node of elem1
  last1 = elem1->last_node;
  next1 = elem1->next_node;
  last2 = elem2->last_node;
  next2 = elem2->next_node;

  //give elem2 position in list of elem1
  if(last1 != NULL) last1->next_node = elem2;
  if(next1 != NULL) next1->last_node = elem2;

  elem2->last_node = last1;
  elem2->next_node = next1;

  //give elem1 position in list of elem2
  if(last2 != NULL) last2->next_node = elem1;
  if(next2 != NULL) next2->last_node = elem1;

  elem1->last_node = last2;
  elem1->next_node = next2;
  return 0;
}

int list_print(struct list_struct* L){
  if(L == NULL)
  {
    printf("Error: list is empty!\n");
    return -1;
  }
  printf("---------------------------------Danh sach sinh vien------------------------------------\n");
  struct student_struct* ptr = L->list_start;
  while(ptr != NULL){
    printf("\nTen sinh vien: %s\n", ptr->name);
    printf("Lop sinh vien: %s\n", ptr->class);
    ptr = ptr->next_node;
  }
  return 0;
}
