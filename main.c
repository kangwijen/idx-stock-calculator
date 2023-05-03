#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "price.h"
#include "gain.h"

//IDX Stock Calculator v1.2
//Made by kangwijen / @thatryzenguy

int main() {
	char intro1[100] = "  _____ _______   __   _____ _             _       _____      _            _       _             \n";
	char intro2[100] = " |_   _|  __ \\ \\ / /  / ____| |           | |     / ____|    | |          | |     | |            \n";
	char intro3[100] = "   | | | |  | \\ V /  | (___ | |_ ___   ___| | __ | |     __ _| | ___ _   _| | __ _| |_ ___  _ __ \n";
	char intro4[100] = "   | | | |  | |> <    \\___ \\| __/ _ \\ / __| |/ / | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|\n";
	char intro5[100] = "  _| |_| |__| / . \\   ____) | || (_) | (__|   <  | |___| (_| | | (__| |_| | | (_| | || (_) | |   \n";
	char intro6[100] = " |_____|_____/_/ \\_\\ |_____/ \\__\\___/ \\___|_|\\_\\  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|   \n";
	int choice;
	char choice1[5], choice2[5], choice3[5];
    FILE *settings = fopen("settings.txt", "a");
	
    do {
    	system("cls");
        printf("%s%s%s%s%s%s", intro1, intro2, intro3, intro4, intro5, intro6);
        printf("				by kangwijen || @thatryzenguy\n");
        printf(" ====================================================\n");
        printf(" | 1. ARA/ARB Calculator 	[New Feature]	   |\n");
        printf(" | 2. Warrant BEP Calculator 	[Beta]		   |\n");
        printf(" | 3. Preferences 		[In Development]   |\n");
        printf(" | 4. Quit					   |\n");
        printf(" ====================================================\n");
        printf(" Choose: ");
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
            case 2:
				do {
				    system("cls");
				    printf("Warrant BEP Calculator\n");
				    float lot_induk = 10000.00, multiplier, harga_induk, saham, waran;
				    printf("Enter stock price: ");
				    scanf("%f", &harga_induk);
				    printf("Enter warrant ratio (stock:warrant): ");
				    scanf("%f:%f", &saham, &waran);
				    
				    multiplier = waran/saham;
				    float loss = harga_induk - (harga_induk*0.07);
				    float lot_waran = multiplier * lot_induk;
				    float result, price;
				    float base_induk = lot_induk * harga_induk * 100.00;
				    float base_loss = lot_induk * 100 * loss;
				    result = (base_loss + (price * lot_waran * 100.00)) / base_induk - 1;
				    int i;
				    for (i = 0; result <= 0.00; i++) {
//				        printf("result %i %f%%\n", i, result*100.00);
				        price++;
				        result = (base_loss + (price * lot_waran * 100.00)) / base_induk - 1;
				    }
				    printf("Sell warrant at %.0f | Gain %.2f%%\n", price, result*100.00);
				
				    printf("Calculate again? (Y/N): ");
				    scanf("%s", choice2);
				} while (strcmp(choice2, "N") != 0);
				break;
            case 3:
            	do{
            		printf("Exit? (Y/N): ");
					scanf("%s", choice3);   	
				} while(strcmp(choice3, "N") != 0);
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
