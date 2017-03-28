struct student_struct{
  char name[56];
  char class[28];
  struct student_struct* next_node;
  struct student_struct* last_node;
}

struct list_struct {
  struct student_struct* list_start;
  struct student_struct* list_end;
}
