
int IsIn(int record[81], int num) {
	int i;
	for (i = 0; i < 81; i++) if (num == record[i]) return TRUE;
	return FALSE;
}

void Save(int sudoku[10][10], int tran) {
	if (tran < 0) return;
	int row, column, num;
	row = (tran - 1) / 81 + 1;
	column = (tran - (row - 1) * 81) / 9 + 1;
	if ((tran - (row - 1) * 81) % 9 == 0) {
		num = 9;
		column--;
	}
	else num = tran - (row - 1) * 81 - (column - 1) * 9;
	sudoku[row][column] = num;
}

void PrintSudoku(int sudoku[10][10]) {
	int i, j;
	for (i = 1; i < 10; i++) {
		printf(" ------------------------------------\n");
		for (j = 1; j < 10; j++) {
			if (sudoku[i][j] == 0) printf("Ø­ ");
			else printf("Ø­%d ", sudoku[i][j]);
		}
		printf("Ø­\n");
	}
	printf(" ------------------------------------\n");
}

void PrintSudoku2(int sudoku[10][10], int sudoku1[10][10]) {
	int i, j;
	for (i = 1; i < 10; i++) {
		printf(" ------------------------------------\n");
		for (j = 1; j < 10; j++) {
			if (sudoku1[i][j] == 0) printf("Ø­  ");
			else if (sudoku[i][j]) printf("Ø­%d*", sudoku[i][j]);
			else printf("Ø­%d ", sudoku1[i][j]);
		}
		printf("Ø­\n");
	}
	printf(" ------------------------------------\n");
}
void PrintSolution(int sudoku[10][10], int solution[1000]) {
	int i, j;
	int row, column, num;
	for (i = 1; i <= 729; i++) {
		if (solution[i] == 1) {
			row = (i - 1) / 81 + 1;
			column = (i - (row - 1) * 81) / 9 + 1;
			if ((i - (row - 1) * 81) % 9 == 0) {
				num = 9;
				column--;
			}
			else num = i - (row - 1) * 81 - (column - 1) * 9;
			sudoku[row][column] = num;
		}
	}
	for (i = 1; i < 10; i++) {
		printf(" ------------------------------------\n");
		for (j = 1; j < 10; j++) {
			printf("Ø­%d ", sudoku[i][j]);
		}
		printf("Ø­\n");
	}
	printf(" ------------------------------------\n");
	printf("\n");
}

void PrintInitial(HNode* head, int sudoku[10][10]) {
	int i, j;
	HNode* p = head;
	while (p != NULL) {
		Save(sudoku, p->first->data);
		p = p->next;
	}
	for (i = 1; i < 10; i++) {
		printf(" ------------------------------------\n");
		for (j = 1; j < 10; j++) {
			if (sudoku[i][j] == 0) printf("Ø­  ");
			else printf("Ø­%d*", sudoku[i][j]);
		}
		printf("Ø­\n");
	}
	printf(" ------------------------------------\n");
}

void CreateSudoku(HNode* head) {
	int i, j, k;
	//¸ñÔ¼Êø
	HNode* p = head;
	Node* q = NULL;
	while (p->next != NULL) p = p->next;
	for (i = 1; i <= 729; i++) {
		if ((i - 1) % 9 == 0) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
		}
		q->data = i;
		if (i % 9 != 0) {
			q->next = (Node*)malloc(sizeof(Node));
			q = q->next;
		}
		q->next = NULL;
	}

	for (i = 1; i < 729; i++) {
		for (j = i + 1; j <= ((i - 1) / 9 + 1) * 9; j++) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			q->data = -i;
			q->next = (Node*)malloc(sizeof(Node));
			q->next->next = NULL;
			q->next->data = -j;
		}
	}

	//ÐÐÔ¼Êø
	for (k = 1; k <= 649; k += 81) {
		for (i = k; i <= k + 8; i++) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			for (j = i; j <= i + 72; j += 9) {
				q->data = j;
				if (j != i + 72) {
					q->next = (Node*)malloc(sizeof(Node));
					q = q->next;
				}
				q->next = NULL;
			}
		}
	}

	for (i = 1; i <= 720; i++) {
		for (j = i + 9; j <= ((i - 1) / 81 + 1) * 81; j += 9) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			q->data = -i;
			q->next = (Node*)malloc(sizeof(Node));
			q->next->next = NULL;
			q->next->data = -j;
		}
	}

	//ÁÐÔ¼Êø
	for (k = 1; k <= 73; k += 9) {
		for (i = k; i <= k + 8; i++) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			for (j = i; j <= i + 648; j += 81) {
				q->data = j;
				if (j != i + 648) {
					q->next = (Node*)malloc(sizeof(Node));
					q = q->next;
				}
				q->next = NULL;
			}
		}
	}

	for (i = 1; i <= 648; i++) {
		for (j = i + 81; j <= (i - (i - 1) / 81 * 81 - 1) / 9 * 9 + 657; j += 81) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			q->data = -i;
			q->next = (Node*)malloc(sizeof(Node));
			q->next->next = NULL;
			q->next->data = -j;
		}
	}
	//ºÐÔ¼Êø
	int count = 0, flag = 0;
	for (i = 1; i <= 541; i += 27) {
		if ((i - 1) % 81 == 0 && i != 1) flag = 1;
		if (flag == 1) {
			count++;
			if (count % 7 != 0) continue;
			flag = 0;
		}
		for (j = i; j <= i + 8; j++) {
			p->next = (HNode*)malloc(sizeof(HNode));
			p = p->next;
			p->first = NULL;
			p->next = NULL;
			q = (Node*)malloc(sizeof(Node));
			p->first = q;
			for (k = j; k <= j + 18; k += 9) {
				q->data = k;
				q->next = (Node*)malloc(sizeof(Node));
				q = q->next;
				q->next = NULL;
			}
			for (k = j + 81; k <= j + 99; k += 9) {
				q->data = k;
				q->next = (Node*)malloc(sizeof(Node));
				q = q->next;
				q->next = NULL;
			}
			for (k = j + 162; k <= j + 180; k += 9) {
				q->data = k;
				if (k != j + 180) {
					q->next = (Node*)malloc(sizeof(Node));
					q = q->next;
				}
				q->next = NULL;
			}
		}
	}

	int trig1 = 1, trig2 = 1, cou = 0, t = 0;
	for (t = 1; t <= 55; t += 27) {
		trig1 = 1, trig2 = 1, cou = 0;
		for (i = t; i <= t + 171; i += 9) {
			if (trig1 && i > 20 + t && i < 80 + t)
				continue;
			if (i > 80 + t) trig1 = 0;
			if (trig2 && i > 101 + t && i < 162 + t) continue;
			if (i > 162 + t) trig2 = 0;
			for (j = i; j <= i + 8; j++) {
				for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 1.8) goto loop;
				for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 0.9) goto loop;
				for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}
			loop:
				;
			}
			cou++;
		}
	}

	for (t = 244; t <= 298; t += 27) {
		cou = 0, trig1 = 1, trig2 = 1;
		for (i = t; i <= t + 171; i += 9) {
			if (trig1 && i > 263 + t - 244 && i < 323 + t - 244) continue;
			if (i > 323 + t - 244) trig1 = 0;
			if (trig2 && i > 344 + t - 244 && i < 404 + t - 244) continue;
			if (i > 404 + t - 244) trig2 = 0;
			for (j = i; j <= i + 8; j++) {
				for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 1.8) goto loop1;
				for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 0.9) goto loop1;
				for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}
			loop1:
				;
			}
			cou++;
		}
	}

	for (t = 487; t <= 541; t += 27) {
		cou = 0, trig1 = 1, trig2 = 1;
		for (i = t; i <= t + 171; i += 9) {
			if (trig1 && i > 507 + t - 487 && i < 566 + t - 487) continue;
			if (i > 566 + t - 487) trig1 = 0;
			if (trig2 && i > 587 + t - 487 && i < 648 + t - 487) continue;
			if (i > 648 + t - 487) trig2 = 0;
			for (j = i; j <= i + 8; j++) {
				for (k = j + 9; k <= j + 18 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 1.8) goto loop2;
				for (k = j + 81 - cou % 3 * 9; k <= j + 99 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}

				if ((float)cou / 3 > 0.9) goto loop2;
				for (k = j + 162 - cou % 3 * 9; k <= j + 180 - cou % 3 * 9; k += 9) {
					p->next = (HNode*)malloc(sizeof(HNode));
					p = p->next;
					p->first = NULL;
					p->next = NULL;
					q = (Node*)malloc(sizeof(Node));
					p->first = q;
					q->data = -j;
					q->next = (Node*)malloc(sizeof(Node));
					q->next->next = NULL;
					q->next->data = -k;
				}
			loop2:
				;
			}
			cou++;
		}
	}
}
