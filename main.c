#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//IDX Stock Calculator v1.1
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
	int choice;
	char choice1[5];
	
    do {
    	system("cls");
        printf("IDX Stock Calculator!\n");
        printf("by kangwijen || @thatryzenguy\n");
        printf("=============================\n");
        printf("1. ARA/ARB Calculator\n");
        printf("4. Quit\n");
        printf("=============================\n");
        printf("Choose: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            	do{
	            	system("cls");
	                printf("ARA/ARB Calculator\n");
				    double init_price, max_gain;
					float lots, base_price;
				    int days;
				    char input[4];
				    printf("Enter initial price: ");
				    scanf("%lf", &init_price);
				    printf("Enter lots: ");
				    scanf("%f", &lots);
				    printf("Enter input (ARA or ARB): ");
				    scanf("%s", input);
				    printf("Enter days: ");
				    scanf("%d", &days);
				    
				    base_price = lots*init_price*100;
				    printf("Base | Price: %.0f | Lots: %.0f | Total: %.0f\n", init_price, lots, lots*init_price*100);
				    int i = 0;
				    for(i; i<days; i++){
					    max_gain = get_max_gain(init_price, input);
					    double price = get_price(init_price, max_gain);
					    printf("Day %i | %s Price: %.0f | Lots: %.0f | Total: %.0f | Profit: %.0f\n", i+1, input, price, lots, lots*price*100, lots*price*100-base_price);
					    init_price = price;
					}
					printf("Calculate again? (Y/N): ");
					scanf("%s", choice1);          		
				} while(strcmp(choice1, "N") != 0);
                break;
                
            case 4:
                printf("Goodbye!\n");
            	break;
            	
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}















