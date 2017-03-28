struct student_struct{
  char name[56];
  char class[28];
  struct student_struct* next_node;
  struct student_struct* last_node;
};

struct list_struct {
  struct student_struct* list_start;
  struct student_struct* list_end;
};

struct list_struct* get_user_list(void);
int add_elem_to_list(struct list_struct* L, struct student_struct* E);
int selection_sort_list_ascent(struct list_struct* L);
int elem_swap(struct student_struct* elem1, struct student_struct* elem2);
int list_print(struct list_struct* L);
