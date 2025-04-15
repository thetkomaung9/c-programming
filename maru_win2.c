#include <windows.h>
#include <stdio.h>

#define MAX_TODO 100
#define MAX_LENGTH 256
#define ID_ADD 1
#define ID_INPUT 2
#define ID_LISTBOX 3

char todos[MAX_TODO][MAX_LENGTH];
int todo_count = 0;
HWND hInput, hList;

void LoadTodos() {
    FILE *file = fopen("todo.txt", "r");
    if (!file) return;
    while (fgets(todos[todo_count], MAX_LENGTH, file)) {
        todos[todo_count][strcspn(todos[todo_count], "\n")] = 0; // 줄바꿈 제거
        todo_count++;
    }
    fclose(file);
}

void SaveTodos() {
    FILE *file = fopen("todo.txt", "w");
    if (!file) return;
    for (int i = 0; i < todo_count; i++) {
        fprintf(file, "%s\n", todos[i]);
    }
    fclose(file);
}

void RefreshList() {
    SendMessage(hList, LB_RESETCONTENT, 0, 0);
    for (int i = 0; i < todo_count; i++) {
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)todos[i]);
    }
}

void AddTodo(HWND hwnd) {
    char text[MAX_LENGTH];
    GetWindowText(hInput, text, MAX_LENGTH);
    if (strlen(text) == 0) return;

    strcpy(todos[todo_count++], text);
    SetWindowText(hInput, "");
    RefreshList();
    SaveTodos();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            hInput = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                  10, 10, 260, 25, hwnd, (HMENU)ID_INPUT, NULL, NULL);

            CreateWindow("BUTTON", "추가", WS_CHILD | WS_VISIBLE,
                         280, 10, 80, 25, hwnd, (HMENU)ID_ADD, NULL, NULL);

            hList = CreateWindow("LISTBOX", NULL,
                                 WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
                                 10, 50, 350, 300, hwnd, (HMENU)ID_LISTBOX, NULL, NULL);

            LoadTodos();
            RefreshList();
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_ADD) {
                AddTodo(hwnd);
            }
            break;

        case WM_DESTROY:
            SaveTodos();
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    const char *className = "MaruApp";

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(className, "마루 - 할 일 목록",
                             WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
                             100, 100, 400, 400,
                             NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
