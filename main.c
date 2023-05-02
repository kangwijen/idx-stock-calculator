#include <stdio.h>
#include <math.h>
#include <string.h>

//IDX Stock Calculator v1
//Made by kangwijen

double get_price(double init_price, double max_gain) {
    double price = init_price * (1 + max_gain);
    if (max_gain >= 0) {
        if (price < 50) {
            return -1;
        } else if (price == 50){
        	return 50;
		} else if (price <= 200) {
            return floor(price);
        } else if (price <= 500) {#include <stdio.h>
#include <math.h>
#include <string.h>

//IDX Stock Calculator v1
//Made by kangwijen

double get_price(double init_price, double max_gain) {
    double price = init_price * (1 + max_gain);
    if (max_gain >= 0) {
        if (price < 50) {
            return -1;
        } else if (price == 50){
        	return 50;
		} else if (price <= 200) {
            return floor(price);
        } else if (price <= 500) {
            return floor(price / 2) * 2.0;
        } else if (price <= 2000) {
            return floor(price / 5) * 5.0;
        } else if (price <= 5000) {
            return floor(price / 10) * 10.0;
        } else {
            return floor(price / 25) * 25.0;
        }
    } else {
        if (price < 50) {
            return -1;
        } else if (price == 50){
        	return 50;
		} else if (price <= 200) {
            return ceil(price);
        } else if (price <= 500) {
            return ceil(price / 2) * 2.0;
        } else if (price <= 2000) {
            return ceil(price / 5) * 5.0;
        } else if (price <= 5000) {
            return ceil(price / 10) * 10.0;
        } else {
            return ceil(price / 25) * 25.0;
        }
    }
}

double get_max_gain(double price, char* input) {
    if (price <= 50) {
        return 0.0;
    } else if (strcmp(input, "ARA") == 0 || strcmp(input, "ara") == 0) {
        if (price >= 50 && price <= 200) {
            return 0.35;
        } else if (price <= 5000) {
            return 0.25;
        } else {
            return 0.20;
        }
    } else {
        return -0.07;
    }
}

int main() {
    double init_price, max_gain;
    char input[4];
    printf("Enter initial price: ");
    scanf("%lf", &init_price);
    printf("Enter input (ARA or ARB): ");
    scanf("%s", input);
    max_gain = get_max_gain(init_price, input);
    double price = get_price(init_price, max_gain);
    printf("%s Price: %.2f\n", input, price);
    return 0;
}









            return floor(price / 2) * 2.0;
        } else if (price <= 2000) {
            return floor(price / 5) * 5.0;
        } else if (price <= 5000) {
            return floor(price / 10) * 10.0;
        } else {
            return floor(price / 25) * 25.0;
        }
    } else {
        if (price < 50) {
            return -1;
        } else if (price == 50){
        	return 50;
		} else if (price <= 200) {
            return ceil(price);
        } else if (price <= 500) {
            return ceil(price / 2) * 2.0;
        } else if (price <= 2000) {
            return ceil(price / 5) * 5.0;
        } else if (price <= 5000) {
            return ceil(price / 10) * 10.0;
        } else {
            return ceil(price / 25) * 25.0;
        }
    }
}

double get_max_gain(double price, char* input) {
    if (price <= 50) {
        return 0.0;
    } else if (strcmp(input, "ARA") == 0) {
        if (price >= 50 && price <= 200) {
            return 0.35;
        } else if (price <= 5000) {
            return 0.25;
        } else {
            return 0.20;
        }
    } else {
        return -0.07;
    }
}

int main() {
    double init_price, max_gain;
    char input[4];
    printf("Enter initial price: ");
    scanf("%lf", &init_price);
    printf("Enter input (ARA or ARB): ");
    scanf("%s", input);
    max_gain = get_max_gain(init_price, input);
    double price = get_price(init_price, max_gain);
    printf("%s Price: %.2f\n", input, price);
    return 0;
}








