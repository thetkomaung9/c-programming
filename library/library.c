#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define FILE_NAME "library.txt"

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

Book books[MAX_BOOKS];
int book_count = 0;

void load_books() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;

    while (fscanf(fp, "%d %[^\n] %[^\n]", &books[book_count].id,
                  books[book_count].title, books[book_count].author) != EOF) {
        book_count++;
    }

    fclose(fp);
}

void save_books() {
    FILE *fp = fopen(FILE_NAME, "w");
    for (int i = 0; i < book_count; i++) {
        fprintf(fp, "%d\n%s\n%s\n", books[i].id, books[i].title, books[i].author);
    }
    fclose(fp);
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("더 이상 도서를 추가할 수 없습니다.\n");
        return;
    }

    printf("도서 ID: ");
    scanf("%d", &books[book_count].id);
    getchar(); // buffer clear

    printf("도서 제목: ");
    fgets(books[book_count].title, TITLE_LEN, stdin);
    books[book_count].title[strcspn(books[book_count].title, "\n")] = 0;

    printf("저자: ");
    fgets(books[book_count].author, AUTHOR_LEN, stdin);
    books[book_count].author[strcspn(books[book_count].author, "\n")] = 0;

    book_count++;
    printf("도서가 추가되었습니다.\n");
}

void list_books() {
    printf("\n[📚 도서 목록]\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. ID: %d | 제목: %s | 저자: %s\n", i + 1,
               books[i].id, books[i].title, books[i].author);
    }
}

void search_book() {
    char keyword[TITLE_LEN];
    printf("검색할 도서 제목 또는 저자 입력: ");
    getchar();
    fgets(keyword, TITLE_LEN, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    printf("\n[🔍 검색 결과]\n");
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("ID: %d | 제목: %s | 저자: %s\n",
                   books[i].id, books[i].title, books[i].author);
        }
    }
}

void delete_book() {
    int id;
    printf("삭제할 도서 ID 입력: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
            found = 1;
            printf("도서가 삭제되었습니다.\n");
            break;
        }
    }

    if (!found) {
        printf("해당 ID의 도서를 찾을 수 없습니다.\n");
    }
}

int main() {
    int choice;
    load_books();

    while (1) {
        printf("\n=== 📖 도서 관리 시스템 ===\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 목록 보기\n");
        printf("3. 도서 검색\n");
        printf("4. 도서 삭제\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_book(); break;
            case 2: list_books(); break;
            case 3: search_book(); break;
            case 4: delete_book(); break;
            case 5:
                save_books();
                printf("저장 후 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
