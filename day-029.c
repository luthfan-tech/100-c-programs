//Program 029 — Electricity Bill Calculator (Tiered Slabs and Surcharges)

#include <stdio.h>

#define MINIMUM_CHARGE 50.00
#define SURCHARGE_THRESHOLD 500.00
#define SURCHARGE_RATE 0.20

int main(void) {
    double units = 0.0;

    printf("Enter total electricity units consumed: ");
    if (scanf("%lf", &units) != 1 || units < 0.0) {
        printf("Error: Please enter a valid non-negative number for units.\n");
        return 1;
    }

    double base_bill = 0.0;

    /*
     * Progressive Slab Schedule:
     * First 50 units:   @ Rs. 0.50 / unit
     * Next 100 units:  @ Rs. 0.75 / unit (units 51 to 150)
     * Next 100 units:  @ Rs. 1.20 / unit (units 151 to 250)
     * Above 250 units: @ Rs. 1.50 / unit
     */
    if (units <= 50.0) {
        base_bill = units * 0.50;
    } else if (units <= 150.0) {
        base_bill = (50.0 * 0.50) + ((units - 50.0) * 0.75);
    } else if (units <= 250.0) {
        base_bill = (50.0 * 0.50) + (100.0 * 0.75) + ((units - 150.0) * 1.20);
    } else {
        base_bill = (50.0 * 0.50) + (100.0 * 0.75) + (100.0 * 1.20) + ((units - 250.0) * 1.50);
    }

    /* Apply mandatory connection minimum charge if consumption is negligible */
    if (base_bill < MINIMUM_CHARGE) {
        base_bill = MINIMUM_CHARGE;
    }

    /* Additional surcharge check */
    double surcharge_amount = 0.0;
    if (base_bill > SURCHARGE_THRESHOLD) {
        surcharge_amount = base_bill * SURCHARGE_RATE;
    }

    double total_bill = base_bill + surcharge_amount;

    printf("\n--- Electricity Billing Statement ---\n");
    printf("Units Consumed:     %.2f units\n", units);
    printf("Energy Base Charge: Rs. %.2f\n", base_bill);
    if (surcharge_amount > 0.0) {
        printf("Surcharge (20%%):    Rs. %.2f\n", surcharge_amount);
    } else {
        printf("Surcharge:          Rs. 0.00 (exempt under Rs. 500 threshold)\n");
    }
    printf("------------------------------------\n");
    printf("Total Amount Due:   Rs. %.2f\n", total_bill);

    return 0;
}

//Expected Output:

/*
Enter total electricity units consumed: 320

--- Electricity Billing Statement ---
Units Consumed:     320.00 units
Energy Base Charge: Rs. 325.00
Surcharge:          Rs. 0.00 (exempt under Rs. 500 threshold)
------------------------------------
Total Amount Due:   Rs. 325.00
*/