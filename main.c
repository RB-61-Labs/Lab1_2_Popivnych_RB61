// підключення бібліотек
#include <stdio.h>
#include <math.h>
#include <conio.h>

// функція відповідно до варіанту 12
double func(double x) {
    return pow(x / 100 - 5, 5)
           - pow(x / 50 + 10, 4)
           - pow(x / 25 - 15, 3)
           - (x * x)
           - 10;
}

// функція виведення таблиці
void table_print(double X1, double delta, unsigned int N) {
    // лічильник виведених рядків
    int r_count = 0;

    // true - перший екран, false - наступні
    bool first_page = true;

    // виведення верхньої частини таблиці
    printf("N \t X \t \t F(X) \n");
    printf("---------------------------------\n");

    // оператор циклу, проходимо всі точки від 1 до N включно
    for (unsigned int i = 1; i <= N; i++) {
        // перевірка на заповнення екрана порцією в 5 рядків
        if (r_count == 5) {
            r_count = 0; // скидаємо лічильник для наступної сторінки

            if (first_page == 1) {
                // на першому екрані виводимо текстове повідомлення та чекаємо клавішу
                printf("press any key to continue...\n");
                getch();
                first_page = 0; // перемикаємо стан, перший екран завершено
            } else { getch(); } // на наступних екранах зупиняємосб без тексту
        }

        // друк поточного рядка таблиці
        printf("%u \t %.2f \t \t %.2f \n", i, X1, func(X1));

        // зміщення аргументу на крок delta
        X1 += delta;

        // збільшення лічильника рядків
        r_count++;
    }
}

int main() {
    double X1, X2, delta;
    unsigned int N;
    int mode;

    // вибір режиму
    printf("Enter mode [1, 2]: ");
    scanf("%d", &mode);


    // перевірка коректності вибору режиму
    if (mode != 1 && mode != 2) {
        printf("invalid mode \n");
        return 0;
    }


    // введення x1 та x2
    printf("Enter X1: ");
    scanf("%lf", &X1);

    printf("Enter X2: ");
    scanf("%lf", &X2);

    // початкова межа не може бути більшою за кінцеву
    if (X1 > X2) { printf("X2 cant be > than X1\n"); return 0; }

    if (mode == 1) {
        // режим 1. введення кількості точок N та обчислення кроку delta
        printf("Enter N: ");
        scanf("%u", &N);

        // кількість точок має бути не менше 2
        if (N <= 1) { printf("N cant be <= 1\n"); return 0; }

        delta = (X2 - X1) / (N - 1);
    } else if (mode == 2) {
        // режим 2. введення кроку delta та обчислення кількості точок N
        printf("Enter delta: ");
        scanf("%lf", &delta);

        // крок не може бути від'ємним
        if (delta < 0) { printf("delta cant be < 0\n"); return 0; }

        // обчислення кількості точок з приведенням до цілого числа
        N = (unsigned int)((X2 - X1) / delta) + 1;
    }

    // виведення підсумкових параметрів перед початком друку таблиці
    printf("X1 = %lf, X2 = %lf, N = %u  delta = %lf\n", X1, X2, N, delta);

    // виклик функії друку таблиці
    table_print(X1, delta, N);

    return 0;
}