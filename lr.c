#include <stdio.h>
#define P 3.14
#define SIZE 10

int myfavoritpow(int x, int n){

    for (short i = 0; i < n; i++){
			x *= x;
        }
    return x;
}

char *rewrite(char *str, int n){
    while(str[n+1] != EOF){
        str[n] = str[n+1];
        n++;
    }
    return str;
}

int factorial(int n){
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

float summa(int n, int x,int degree, int fact, int count,float sum) {
    int a=x;
    if(count<=n){
        fact=factorial(fact);
        //printf("%i %i\n", fact, a);
        sum+=(float)a/(float)fact;
        count++;
        a=myfavoritpow(a, degree);
        //printf("%lf\n", sum);
        return summa(n, x, degree + 2, fact + 2, count, sum);
    }
    else
    {
        return sum;
    }
}

float sqr(float x) {
    return x*x;
}


int check(char massive[], char cr, int n) {
    int i;
    for (i=0;i<n;i++)
    {
        if (cr==massive[i])
            return 1;
    }
    return 0;
}

void delete_word(char* string){
    int bow=0, eow=0, flag=0, i=1;
    char vowel[12] = "aeiouyAEIOUY", separators[7]=" .,:;\n";
    while(string[i] != EOF){
        if(check(vowel, string[i], 12) == 1 && check(vowel, string[i-1], 12) == 1)
            flag=1;
        if(check(separators, string[i], 7)){
            eow = i - 1;
            if(flag){
                int b = bow, l =  eow - bow;
                while(string[b + l + 2] != EOF){
                    string[b] = string[b + l + 2];
                    b++;
                }
                i = i - l - 1;
            }
            if(flag){
                bow = i;
            }
            else bow = i + 1;
            flag = 0;
            }
        i++;
        }
        puts(string);
}

void delete_letter(char* string){
    int flag=0, eow=0, a=0, i=0,  bow = 0;
    char vowel[12] = "aeiouyAEIOUY", separators[7]=" .,:;\n",consonant[40]="BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    while(string[i] != EOF){
        if(check(vowel, string[i], 12)){
            flag=1;
            //printf("%c v\n", string[i]);
            }
        if(check(separators, string[i], 7)){
            eow = i-1;
            //printf("%c z %i\n", string[i], i);
            if(flag){
                int b = bow;
                while(!check(separators, string[b],7)){
                    //printf("flag\n");
                    if(check(consonant, string[b], 40)){
                        string = rewrite(string, b);
                        a++;
                    }
                    else b++;
                }
                //printf("%i\n", a);
                //printf("%i\n", i);
                i = i - a;
                a=0;
                //puts(string);
                //printf("%i\n", i);

            }
            if(flag){
                bow = i;
            }
            else bow = i + 1;
            flag = 0;
            //printf("%i\n", flag);

            }
        //printf("%i\n", i);
        i++;
        }
        puts(string);
}

void print_arr(int **arr, int n, int k){
    for(int i = 0; i < n; i++){
        for(int r = 0; r < k; r++)
            printf("%i",arr[i][r]);

    }
}



void laba1() {
	double r, a, m;
	printf("input R \t");
	scanf("%lf", &r);
	printf("input A \t");
	scanf("%lf", &a);
	m = sqr(a) - (P * sqr(r));
	printf("he area of the remaining figure is %lf", m);
}


void laba2() {
	int n, x;
	printf("enter the number of members of the sequence\n");
	scanf("%i", &n);
	printf("enter the number x\n");
	scanf("%i", &x);
	printf("summa %lf",summa(n, x, 1, 1, 1, 0));
}



void laba3() {
    char vowel[12] = "aeiouyAEIOUY", separators[7]=" .,:;\n";
    char a=' ', cr;
    int count=0, first=0, last=0;
    while((cr=getchar()) != EOF){
            if(check(separators, a, 7)){
                if(check(vowel, cr, 12))
                        first=1;
                else first=0;
            }
            if(check(separators, cr, 7)){
                if(check(vowel, a, 12) != 1)
                    last=1;
                else last=0;
                if(last==1 && first==1)
                    count++;
                last=0;
                first=0;
            }

      a=cr;
    }

    printf("%i\n", count);
}
void laba4(){
    char string[100];
    fgets(string, 100, stdin);
    fgets(string, 100, stdin);
    delete_word(string);
}

void laba42(){
    char string[100];
    fgets(string, 100, stdin);
    fgets(string, 100, stdin);
    delete_letter(string);
}



void laba5(){
    int numbers[10], sumchet = 0, sumnechet = 0;
    for(int i=0; i < 10; i++){
        printf("Enter number:\t");
        scanf("%i", &numbers[i]);
    }
    for(int i = 0; i < 10; i++){
        if(numbers[i] % 2 == 0)
            sumchet+=numbers[i];
        else sumnechet+=numbers[i];
    }
    if(sumchet>sumnechet)
        printf("the sum of even numbers %i\n", sumchet);
    else printf("the sum of odd numbers %i\n", sumchet);

}

void laba6(){
    int n, k, i;
    printf("Enter size of array N: ");
    scanf("%i", &n);
    printf("Enter size of array K: ");
    scanf("%i", &k);
    int numbers[n][k];

    for(int i = 0; i < n; i++)
        for(int t = 0; t < k; t++){
            printf("Enter number: ");
            scanf("%i", &numbers[i][t]);
        }

    int min = numbers[0][0];
    int max = numbers[0][0];

    for(int i=0; i<n; i++){
        for(int t=0; t<k; t++){
            if(min > numbers[i][t])
                min = numbers[i][t];
            if(max < numbers[i][t])
                max = numbers[i][t];

        }
    }


    for(int i = 0; i < n; i++){
        for(int t = 0; t < k; t++){
            if(numbers[i][t] < 0){
                numbers[i][t] = min;

            }
            else numbers[i][t] = max;


        }
    }
    //printf("he he he\n");

    //print_arr(numbers, n, k);
    for(int i = 0; i < n; i++){
        for(int t = 0; t < k; t++){
            printf("%i ", numbers[i][t]);
        }
        printf("\n");
    }

}


void laba52(){
    int numbers[10], flag = 0;
    for(int i=0; i < 10; i++){
        printf("Enter number:\t");
        scanf("%i", &numbers[i]);
    }
    for(int i = 1; i < 5; i++){
            if(numbers[i]>numbers[i - 1])
                flag = 1;
            else flag = 0;

    }
    for(int i = 6; i < 10; i++){
        if(numbers[i]<numbers[i - 1])
            flag = 1;
        else flag = 0;
    }
    if(flag)
        printf("It's a mountain of numbers");

}

int laba7(){

    unsigned long num=0,N;
    scanf("%lu", &N);
    while(N)
    {
        num ^= (N & 3);
        N = N >> 2;
        num = num <<2;
    }
    num = num >> 2;
    printf("%lu", num);
    return 0;
}

void shekerSort(double* mass, int count)
{
    int left = 0, right = count - 1; // лева€ и права€ границы сортируемой области массива
    int flag = 1;  // флаг наличи€ перемещений
    // ¬ыполнение цикла пока лева€ граница не сомкнЄтс€ с правой
    // и пока в массиве имеютс€ перемещени€
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемс€ слева направо
        {
            if (mass[i] > mass[i+1]) // если следующий элемент меньше текущего,
            {             // мен€ем их местами
                double t = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = t;
                flag = 1;      // перемещени€ в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемс€ справа налево
        {
            if (mass[i-1] > mass[i]) // если предыдущий элемент больше текущего,
            {            // мен€ем их местами
                double t = mass[i];
                mass[i] = mass[i-1];
                mass[i-1] = t;
                flag = 1;    // перемещени€ в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
        if(flag == 0) break;
    }
}
