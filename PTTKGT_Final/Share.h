#pragma once
int M, N;
int W[100], V[100], w[100], v[100], balo[100];
int dp[100][100];
int _max = 0, n;
void init() {
	system("cls");
	cout << "Nhap trong luong toi da (M): ";
	cin >> M;
	cout << "Nhap so goi hang (N): ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "<Goi hang " << i + 1 << ">" << endl;
		cout << " - Trong luong: ";
		cin >> W[i];
		cout << " - Gia tri: ";
		cin >> V[i];
		cout << endl;
	}
}


void Try(int k) {
	if (k >= N) {
		int sum_W = 0, sum_V = 0;
		for (int i = 0; i < N; i++) {
			sum_W += w[i];
			sum_V += v[i];
		}
		if (sum_W <= M && sum_V >= _max) {
			n = 0;
			_max = sum_V;
			for (int i = 0; i < N; i++) {
				if (w[i] > 0) {
					balo[n] = i;
					n++;
				}
			}
		}
	}
	else {
		w[k] = W[k]; v[k] = V[k];
		Try(k + 1);
		w[k] = v[k] = 0;
		Try(k + 1);
	}
}
void backtracking() {
	init();
	Try(0);
	cout << "Tong gia tri lon nhat la: " << _max << endl;
	cout << "Balo gom: ";
	for (int i = 0; i < n; i++) {
		cout << "goi hang " << balo[i] + 1;
		if (i < n - 1) cout << ", ";
	}
	cout << endl << endl << "Bam ESC de quay lai.";
}


int getBigger(int a, int b) {
	return a > b ? a : b;
}
void showDP() {
	cout << "             ";
	for (int i = 0; i <= M; i++) {
		cout << i << "    ";
	}
	cout << endl;
	for (int i = 0; i <= N; i++) {
		cout << "Goi hang " << i << " | ";
		for (int j = 0; j <= M; j++) {
			cout << dp[i][j] << "    ";
		}
		cout << endl;
	}
}
void dpHandling() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else {
				if (j < W[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = getBigger(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + V[i - 1]);
				}
			}
		}
	}
}
void getBalo() {
	n = 0;
	for (int i = N; i >= 1; i--) {
		if (dp[i][M] != dp[i - 1][M]) {
			balo[n] = i;
			M = M - W[i - 1];
			n++;
		}
		else continue;
	}
}
void dynamicPrograming() {
	init();
	dpHandling();
	showDP();
	cout << endl << "Tong gia tri lon nhat la: " << dp[N][M] << endl;
	getBalo();
	cout << "Balo gom: ";
	for (int i = 0; i < n; i++) {
		cout << "goi hang " << balo[i];
		if (i < n - 1) cout << ", ";
	}
	cout << endl << endl << "Bam ESC de quay lai.";
}

void exit() {
	char x = _getch();
	while (x != 27) {
		if (x != -32) {
			cout << endl << "Nhan ESC de quay lai." << endl;
		}
		x = _getch();
	}
}
void showMainMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 11);
	cout << setw(57) << right << "|----------> MENU CHINH <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 3; i++) {
		string mess;
		switch (i)
		{
		case 1: mess = "       De quy quay lui       ";
			break;
		case 2: mess = "       Quy hoach dong        ";
			break;
		case 3: mess = "           Thoat             ";
			break;
		}
		cout << setw(22) << "*";
		if (i == k) {
			SetColor(9, 0);
		}
		cout << setw(27) << mess;
		SetColor(0, 11);
		cout << "*" << endl;
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}