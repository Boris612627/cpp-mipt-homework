#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** arr = (char**)malloc(sizeof(char*) * 4);
    
    arr[0] = (char*)malloc(sizeof(char) * 4);
    strcpy(arr[0], "Cat");
    
    arr[1] = (char*)malloc(sizeof(char) * 6);
    strcpy(arr[1], "Mouse");
    
    arr[2] = (char*)malloc(sizeof(char) * 9);
    strcpy(arr[2], "Elephant");
    
    arr[3] = NULL;
    return arr;
}

void print_strings(const char** string_array) {
    int i = 0;
    while (string_array[i] != NULL) {
        printf("%s\n", string_array[i]);
        i++;
    }
}

size_t* get_sizes(const char** string_array) {
    int n = 0;
    while (string_array[n] != NULL) {
        n++;
    }
    
    size_t* sizes = (size_t*)malloc(sizeof(size_t) * n);
    for (int i = 0; i < n; i++) {
        sizes[i] = strlen(string_array[i]);
    }
    return sizes;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fseek(file, -1, SEEK_END);
    if (ftell(file) > 0) {
        ch = fgetc(file);
        if (ch != '\n') {
            count++;
        }
    }
    
    char** lines = (char**)malloc(sizeof(char*) * (count + 1));
    
    fseek(file, 0, SEEK_SET);
    
    char buf[1024];
    int i = 0;
    while (fgets(buf, 1024, file) != NULL && i < count) {
        int len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }
        
        lines[i] = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
        strcpy(lines[i], buf);
        i++;
    }
    lines[i] = NULL;
    
    fclose(file);
    return lines;
}

void destroy_strings(char*** p_string_array) {
    if (p_string_array == NULL || *p_string_array == NULL) {
        return;
    }
    
    char** arr = *p_string_array;
    int i = 0;
    while (arr[i] != NULL) {
        free(arr[i]);
        i++;
    }
    free(arr);
    *p_string_array = NULL;
}

int compare(const void* a, const void* b) {
    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;
    return strcmp(s1, s2);
}

void sort_strings(char** words) {
    int count = 0;
    while (words[count] != NULL) {
        count++;
    }
    qsort(words, count, sizeof(char*), compare);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    
    char** lines = load_lines(argv[1]);
    if (lines == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }
    
    sort_strings(lines);
    
    FILE* out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("Error: cannot open output file\n");
        destroy_strings(&lines);
        return 1;
    }
    
    int i = 0;
    while (lines[i] != NULL) {
        fprintf(out, "%s\n", lines[i]);
        i++;
    }
    fclose(out);
    
    destroy_strings(&lines);
    return 0;
}
