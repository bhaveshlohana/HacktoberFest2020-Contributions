int main(void) {
    float amount = 0;
    int cents = 0;
    int count = 0;
    int amount_left = 0;

    amount = .30;

    cents = (int)round(amount * 100);

    printf("%d", cents);

    amount_left = cents;

    while (cents - 25 >= 0) {
        count = count + 1;
        amount_left = cents - 25;
    }
    while (amount_left - 10 >= 0) {
        count = count + 1;
        amount_left = amount_left - 10;
    }
    while (amount_left - 5 >= 0) {
        count = count + 1;
        amount_left = amount_left - 5;
    }
    while (amount_left - 1 >= 0) {
        count = count + 1;
        amount_left = amount_left - 1;
    }
    printf("You get %d coins\n", count);
}
