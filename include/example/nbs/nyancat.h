#define MAX_NOTE_LEN 1021
float note_data[MAX_NOTE_LEN][4] = {
	{422, 15, 1.0, 2.1189},
	{845, 15, 1.0, 2.1189},
	{159, 15, 1.0, 2.1189},
	{1109, 0, 1.0, 0.7071},
	{423, 0, 1.0, 0.7937},
	{53, 0, 1.0, 1.0594},
	{369, 0, 1.0, 0.8408},
	{423, 3, 1.0, 1.0},
	{423, 4, 1.0, 0.8908},
	{52, 4, 1.0, 0.8408},
	{53, 4, 1.0, 0.8908},
	{317, 4, 1.0, 0.8908},
	{53, 4, 1.0, 0.8408},
	{53, 4, 1.0, 0.8908},
	{317, 3, 1.0, 1.1224},
	{0, 7, 1.0, 0.8408},
	{105, 7, 1.0, 0.8908},
	{106, 7, 1.0, 1.0},
	{0, 7, 0.5, 0.8408},
	{106, 7, 0.5, 0.8908},
	{105, 3, 1.0, 1.1224},
	{0, 7, 1.0, 1.3348},
	{0, 7, 0.5, 1.0},
	{212, 7, 1.0, 0.8408},
	{0, 7, 0.5, 1.3348},
	{105, 7, 1.0, 0.8908},
	{106, 2, 1.0, 0.7071},
	{0, 7, 1.0, 1.0},
	{0, 7, 0.5, 0.8408},
	{106, 7, 1.0, 1.3348},
	{0, 7, 0.5, 0.8908},
	{105, 7, 1.0, 1.4983},
	{0, 7, 0.5, 1.0},
	{106, 7, 1.0, 1.6817},
	{0, 7, 0.5, 1.3348},
	{106, 3, 1.0, 1.1224},
	{0, 7, 1.0, 1.4983},
	{0, 7, 0.5, 1.4983},
	{105, 7, 1.0, 1.2599},
	{0, 7, 0.5, 1.6817},
	{106, 7, 1.0, 1.3348},
	{0, 7, 0.5, 1.4983},
	{106, 2, 1.0, 0.7071},
	{0, 7, 0.5, 1.2599},
	{105, 2, 1.0, 0.7071},
	{0, 7, 1.0, 1.0},
	{0, 7, 0.5, 1.3348},
	{212, 7, 1.0, 0.8408},
	{0, 7, 0.5, 1.0},
	{105, 7, 1.0, 0.8908},
	{106, 3, 1.0, 1.1224},
	{0, 7, 1.0, 1.0},
	{0, 7, 0.5, 0.8408},
	{106, 7, 0.5, 0.8908},
	{105, 7, 1.0, 1.3348},
	{0, 7, 0.5, 1.0},
	{106, 2, 1.0, 0.7071},
	{105, 3, 1.0, 1.1224},
	{0, 7, 1.0, 1.4983},
	{0, 7, 0.5, 1.3348},
	{106, 7, 1.0, 1.2599},
	{106, 0, 1.0, 1.1224},
	{0, 7, 1.0, 1.3348},
	{0, 7, 0.5, 1.4983},
	{105, 7, 1.0, 1.4983},
	{0, 7, 0.5, 1.2599},
	{106, 0, 1.0, 1.0},
	{0, 7, 1.0, 1.7817},
	{0, 7, 0.5, 1.3348},
	{106, 7, 1.0, 1.6817},
	{0, 7, 0.5, 1.4983},
	{105, 2, 1.0, 0.7071},
	{0, 7, 1.0, 1.7817},
	{0, 7, 0.5, 1.7817},
	{106, 2, 1.0, 0.7071},
	{0, 7, 1.0, 1.6817},
	{0, 7, 0.5, 1.6817},
	{106, 2, 1.0, 0.7071},
	{0, 0, 1.0, 0.8908},
	{0, 0, 0.5, 0.8908},
	{0, 0, 0.5, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.0},
	{53, 0, 0.48, 0.8908},
	{0, 6, 0.5, 2.0},
	{52, 0, 0.465, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.0},
	{53, 0, 0.45, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.435, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.2449},
	{53, 0, 0.415, 0.8908},
	{0, 6, 0.5, 2.2449},
	{53, 0, 0.4, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.2449},
	{52, 0, 0.385, 0.8908},
	{53, 0, 1.0, 1.0},
	{0, 0, 0.37, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.5874},
	{53, 0, 0.35, 0.8908},
	{0, 6, 0.5, 1.5874},
	{53, 0, 0.335, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 0, 0.32, 0.8908},
	{0, 6, 0.5, 1.6817},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.305, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.6817},
	{52, 0, 0.29, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.27, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.255, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 2, 1.0, 0.7071},
	{0, 0, 0.24, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.5874},
	{53, 0, 0.225, 0.8908},
	{0, 6, 0.5, 1.5874},
	{53, 0, 0.205, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{52, 0, 0.19, 0.8908},
	{0, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.175, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.16, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.145, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.125, 0.8908},
	{53, 0, 1.0, 1.0},
	{0, 0, 0.11, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{52, 0, 0.095, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.08, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.06, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.045, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{53, 0, 0.03, 0.8908},
	{0, 6, 0.5, 1.4983},
	{52, 0, 0.015, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 0.5, 1.4983},
	{53, 0, 0.0, 0.8908},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.5874},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{52, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.2449},
	{53, 6, 0.5, 2.2449},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.0},
	{52, 6, 0.5, 2.0},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.6817},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.0},
	{105, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.2449},
	{53, 6, 0.5, 2.2449},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.5874},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{52, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 0.5, 1.4983},
	{106, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.4983},
	{105, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.0},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.2449},
	{53, 6, 0.5, 2.2449},
	{52, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.2449},
	{106, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.6817},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.5874},
	{52, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.3348},
	{105, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.1224},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{52, 6, 0.5, 1.4983},
	{53, 1, 0.5, 1.1224},
	{0, 6, 0.5, 1.4983},
	{106, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.5874},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.2449},
	{53, 6, 0.5, 2.2449},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{52, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.6817},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 2.0},
	{52, 6, 0.5, 2.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 2.0},
	{106, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.2449},
	{53, 6, 0.5, 2.2449},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{52, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.5874},
	{53, 6, 0.5, 1.5874},
	{52, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.5874},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 0.5, 1.4983},
	{106, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.3348},
	{105, 2, 1.0, 0.7071},
	{0, 0, 1.0, 0.8908},
	{0, 0, 0.5, 0.8908},
	{0, 0, 0.5, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.48, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.465, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.45, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.435, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.0},
	{52, 0, 0.415, 0.8908},
	{0, 6, 0.5, 1.0},
	{53, 0, 0.4, 0.8908},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.1224},
	{53, 0, 0.385, 0.8908},
	{0, 6, 0.5, 1.1224},
	{53, 0, 1.0, 1.0},
	{0, 0, 0.37, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.35, 0.8908},
	{0, 6, 0.5, 1.3348},
	{52, 0, 0.335, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.32, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.305, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 0, 0.29, 0.8908},
	{0, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.27, 0.8908},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{53, 0, 0.255, 0.8908},
	{0, 6, 0.5, 1.1224},
	{52, 2, 1.0, 0.7071},
	{0, 0, 0.24, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.225, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 0.205, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 0, 0.19, 0.8908},
	{0, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 0, 0.175, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 0, 0.16, 0.8908},
	{0, 6, 0.5, 1.6817},
	{52, 0, 0.145, 0.8908},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 0, 0.125, 0.8908},
	{0, 6, 0.5, 1.3348},
	{53, 0, 1.0, 1.0},
	{0, 0, 0.11, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.7817},
	{53, 0, 0.095, 0.8908},
	{0, 6, 0.5, 1.7817},
	{53, 0, 0.08, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.6817},
	{53, 0, 0.06, 0.8908},
	{0, 6, 0.5, 1.6817},
	{52, 3, 1.0, 0.9438},
	{0, 0, 0.045, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.7817},
	{53, 0, 0.03, 0.8908},
	{0, 6, 0.5, 1.7817},
	{53, 0, 0.015, 0.8908},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 2.0},
	{53, 0, 0.0, 0.8908},
	{0, 6, 0.5, 2.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{105, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{52, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 0.8408},
	{53, 6, 0.5, 0.8408},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 0.8908},
	{53, 6, 0.5, 0.8908},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.3348},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{52, 6, 0.5, 1.1224},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{52, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.0},
	{52, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.2599},
	{53, 6, 0.5, 1.2599},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{52, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.2599},
	{52, 6, 0.5, 1.2599},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.2599},
	{106, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.3348},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{52, 6, 0.5, 1.1224},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{52, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{52, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{52, 6, 0.5, 1.1224},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{52, 6, 0.5, 1.7817},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 0.8408},
	{53, 6, 0.5, 0.8408},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 0.8908},
	{52, 6, 0.5, 0.8908},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 1, 0.5, 0.8908},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 1, 0.5, 0.8908},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{52, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.0},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.0},
	{53, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 1, 0.5, 1.1224},
	{0, 6, 1.0, 1.0},
	{52, 6, 0.5, 1.0},
	{53, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{106, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{52, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.2599},
	{53, 6, 0.5, 1.2599},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.0},
	{52, 6, 0.5, 1.0},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.1224},
	{53, 6, 0.5, 1.1224},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 1.0},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{52, 2, 1.0, 0.7071},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{53, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.6817},
	{53, 6, 0.5, 1.6817},
	{53, 0, 1.0, 1.1224},
	{0, 1, 0.5, 0.6674},
	{0, 6, 1.0, 1.7817},
	{53, 6, 0.5, 1.7817},
	{52, 1, 0.5, 0.6674},
	{0, 6, 1.0, 2.0},
	{53, 6, 0.5, 2.0},
	{53, 0, 1.0, 1.0},
	{0, 1, 0.5, 0.7491},
	{0, 6, 1.0, 1.3348},
	{53, 6, 0.5, 1.3348},
	{53, 1, 0.5, 0.7491},
	{0, 6, 0.5, 1.3348},
	{105, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 1.0, 1.4983},
	{53, 6, 0.5, 1.4983},
	{53, 3, 1.0, 0.9438},
	{0, 1, 0.5, 0.8408},
	{0, 6, 0.5, 1.4983},
};
