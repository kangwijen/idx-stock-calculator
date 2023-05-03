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
