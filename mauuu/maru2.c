#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODOS 100
#define MAX_LENGTH 256
#define FILE_NAME "todo.txt"

typedef struct {
    char text[MAX_LENGTH];
    int done; // 0: 미완료, 1: 완료
} Todo;

Todo todos[MAX_TODOS];
int todo_count = 0;

// 파일에서 목록 불러오기
void load_todos() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (todo_count >= MAX_TODOS) break;
        line[strcspn(line, "\n")] = 0; // 줄바꿈 제거

        todos[todo_count].done = (line[1] == 'x') ? 1 : 0;
        strcpy(todos[todo_count].text, line + 4);
        todo_count++;
    }

    fclose(file);
}

// 목록을 파일에 저장
void save_todos() {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("파일 저장 실패\n");
        return;
    }

    for (int i = 0; i < todo_count; i++) {
        fprintf(file, "[%c] %s\n", todos[i].done ? 'x' : ' ', todos[i].text);
    }

    fclose(file);
}

// 목록 보기
void list_todos() {
    printf("\n[ 마루 - 할 일 목록 ]\n");
    for (int i = 0; i < todo_count; i++) {
        printf("%d. [%c] %s\n", i + 1, todos[i].done ? 'x' : ' ', todos[i].text);
    }
}

// 할 일 추가
void add_todo() {
    if (todo_count >= MAX_TODOS) {
        printf("할 일 목록이 가득 찼습니다.\n");
        return;
    }
    printf("새 할 일을 입력하세요: ");
    getchar(); // 입력 버퍼 비우기
    fgets(todos[todo_count].text, MAX_LENGTH, stdin);
    todos[todo_count].text[strcspn(todos[todo_count].text, "\n")] = 0;
    todos[todo_count].done = 0;
    todo_count++;
    printf("추가 완료!\n");
}

// 할 일 완료 표시
void complete_todo() {
    int index;
    printf("완료할 항목 번호: ");
    scanf("%d", &index);
    if (index < 1 || index > todo_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    todos[index - 1].done = 1;
    printf("완료 처리되었습니다.\n");
}

// 할 일 삭제
void delete_todo() {
    int index;
    printf("삭제할 항목 번호: ");
    scanf("%d", &index);
    if (index < 1 || index > todo_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    for (int i = index - 1; i < todo_count - 1; i++) {
        todos[i] = todos[i + 1];
    }
    todo_count--;
    printf("삭제 완료!\n");
}

int main() {
    int choice;
    load_todos();

    while (1) {
        printf("\n[ 마루 - 할일 목록 프로그램 ]\n");
        printf("1. 목록 보기\n");
        printf("2. 할 일 추가\n");
        printf("3. 완료 표시\n");
        printf("4. 삭제\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: list_todos(); break;
            case 2: add_todo(); break;
            case 3: complete_todo(); break;
            case 4: delete_todo(); break;
            case 5:
                save_todos();
                printf("저장 후 종료합니다.\n");
                return 0;
            default: printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}
