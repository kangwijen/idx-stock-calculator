#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//IDX Stock Calculator v1.2
//Made by kangwijen / @thatryzenguy

double get_price(double init_price, double max_gain, int board) {
    double price = init_price * (1 + max_gain);
    if (max_gain >= 0 && board != 3) {
        if (price < 50) {
            return;
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
    } else if (max_gain < 0 && board != 3) {
        if (price < 50) {
            return;
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
    } else if (max_gain >= 0 && board == 3) {
        if (price < 1) {
            return;
        } else if (price == 1){
        	return 1;
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
    } else if (max_gain < 0 && board == 3) {
//    	puts("Called Function get_price, else if (max_gain < 0 && board == 3)\n");
        if (price < 1) {
//        	puts("Called Function get_price, price < 1\n");
            return;
        } else if (price == 1){
//        	puts("Called Function get_price, price == 1\n");
        	return 1;
		} else if (price <= 200) {
//			puts("Called Function get_price, price <= 200\n");
            return ceil(price);
        } else if (price <= 500) {
//        	puts("Called Function get_price, price <= 500\n");
            return ceil(price / 2) * 2.0;
        } else if (price <= 2000) {
//        	puts("Called Function get_price, price <= 2000\n");
            return ceil(price / 5) * 5.0;
        } else if (price <= 5000) {
//        	puts("Called Function get_price, price <= 5000\n");
            return ceil(price / 10) * 10.0;
        } else {
//        	puts("Called Function get_price, price > 5000\n");
            return ceil(price / 25) * 25.0;
        }
    }
}

double get_max_gain(double price, char* input, int board) {
    if (price <= 50 && board != 3) {
        return 0.0;
    } else if (strcmp(input, "ARA") == 0 || strcmp(input, "ara") == 0) {
    	if (board == 0 || board == 1 || board == 2){
	        if (price >= 50 && price <= 200) {
	            return 0.35;
	        } else if (price <= 5000) {
	            return 0.25;
	        } else {
	            return 0.20;
	    	}
		} else if (board == 3){
			return 0.1;
		} else {
			return -3;
		}
    } else if (strcmp(input, "ARB") == 0 || strcmp(input, "arb") == 0){
    	if (board == 0){
			return -0.07;
		} else if (board == 1){
			return -0.15;
		} else if (board == 2){
	        if (price >= 50 && price <= 200) {
	            return -0.35;
	        } else if (price <= 5000) {
	            return -0.25;
	        } else {
	            return -0.20;
	    	}			
		} else if (board == 3){
//			puts("Called function get_max_gain, else if (board == 3)\n");
			return -0.1;
		} else {
			return -3;
		}        
    } else {
    	return -3;
	}
}

int main() {
	int choice;
	char choice1[5], choice3[5];
    FILE *settings = fopen("settings.txt", "a");
	
    do {
    	system("cls");
        printf("IDX Stock Calculator!\n");
        printf("by kangwijen || @thatryzenguy\n");
        printf("=============================\n");
        printf("1. ARA/ARB Calculator\n");
        printf("3. Preferences [In Development]\n");
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
					float lots, fee = 0.0015;
				    int days, board = 0;
				    char input[4];
				    printf("Enter initial price: ");
				    scanf("%lf", &init_price);
				    printf("Enter lots: ");
				    scanf("%f", &lots);
				    printf("Enter input (ARA or ARB): ");
				    scanf("%s", input);
				    printf("Enter days: ");
				    scanf("%d", &days);
				    printf("Select board\n");
				    printf("0. Utama/Pengembangan (Asimetris ARB 7%%)\n");
				    printf("1. Utama/Pengembangan (Asimetris ARB 15%%)\n");
				    printf("2. Utama/Pengembangan (Simetris ARA = ARB)\n");
				    printf("3. Akselerasi (ARA & ARB 10%%)\n");
				    printf("Enter board: ");
				    scanf("%d", &board);	
								    
					float base_cost = lots*init_price*100, base_price = init_price;
					printf("Day %-3i | Base Price: Rp%6.0f | Lots: %8.0f | Total: Rp%15.0f\n", 0, init_price, lots, lots*init_price*100);
					int i = 0;
					for(i; i < days && i != 1000; i++){
//						printf("Loop %d\n", i+1);
						max_gain = get_max_gain(init_price, input, board);
						double price = get_price(init_price, max_gain, board);
//						fee 
						printf("Day %-3i | %-4s Price: Rp%6.0f | Lots: %8.0f | Total: Rp%15.0f | Net Profit/Loss: Rp%15.0f | Gain/Loss Daily: %4.2f%% | Total Gain/Loss: %3.2f%%\n", i+1, input, price, lots, lots*price*100, lots*price*100-base_cost, ((price/init_price)-1)*100, ((price/base_price)-1)*100);
						init_price = price;
					}
					printf("Calculate again? (Y/N): ");
					scanf("%s", choice1);          		
				    
				} while(strcmp(choice1, "N") != 0);
                break;
            case 3:
            	do{
            		printf("Save settings? (Y/N): ");
					scanf("%s", choice3);   	
				} while(strcmp(choice3, "Y") != 0);
				fclose(settings);
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
