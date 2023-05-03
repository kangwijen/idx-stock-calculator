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
