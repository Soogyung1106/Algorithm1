/*
<백준 1181번 문제>
input: 알파벳 소문자로 이루어진 N개의 단어 
(단, 1<=N<=20,000)
output:
정렬 
1. 길이가 짧은 것부터
2. 길이가 같으면 사전순으로 
(단, 같은 단어가 중복시 -> 한 번만 출력)
*/
#define _CRT_SECURE_NO_WARNINGS  //scanf_s 사용x
#include <stdio.h>
#include <stdlib.h> //malloc()함수 
#include <string.h> //strlen(), strcmp(), strcpy()함수 

int main() {

	int n; //사용자가 입력할 단어의 갯수
	char tmp[50]; //단어의 길이 비교할 때 쓰일 임시 배열
	int min; //사전순으로 정렬시 필요

	
	//(1) 몇 개의 단어를 입력할지 설정
	printf("단어 N개 입력: ");
	scanf("%d", &n);

	//길이 20짜리의 char형 N개의 2차원 배열 동적할당 
	char **arr = (char**)malloc(sizeof(char*)*n); //단어 n개(배열 n개)를 저장하기 위한 포인터 n개 

	for (int i = 0; i < n; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 50);//(조건: 주어진 문자열의 길이는 50을 넘지 않는다.)
	}

	//(2) n개의 단어 입력 시작
	for (int i = 0; i < n;i++) {
		scanf("%s", arr[i]); //arr[i]에 매 행의 주소가 담겨져 있음 
	}


	//(3)길이보다 사전순으로 우선 정렬
	//(조건2: 길이가 같으면 사전순으로 )

	for (int i = 0; i < n - 1; i++) {
		
		min = i;  //min을 사전순 i번째 위치로 설정

		for (int k = i + 1; k < n; k++) {  //인덱스 0과 1,2,3,4,...비교해서 사전순 0의 위치 찾기 / 인덱스 1과 2,3,4,5...비교해서 사전순 1의 위치 찾기 

			if (strcmp(arr[min], arr[k]) > 0) //arr[k]가 arr[min] 보다 사전순으로 앞에 올 경우
				min = k; //인덱스 k로 변경
		}
		
		//사전순 i의 위치에 있는 단어가 i의 위치에 있도록 자리 바꿔주기
		strcpy(tmp, arr[i]);
		strcpy(arr[i], arr[min]);
		strcpy(arr[min], tmp);
			
	}

	//(4) 길이순으로 정렬
	//(조건1: 길이가 짧은 것부터)
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {

			//길이 비교
			if (strlen(arr[j]) > strlen(arr[j + 1])) { //앞 단어가 뒷 단어보다 긴 단어일 경우

				//더 짧은 단어가 앞에 위치하도록 재배치
				strcpy(tmp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], tmp);

			}
		}
	}


	//(5) 출력
	printf("\n");

	for (int i = 0; i < n; i++) {

		//(조건: 같은 단어가 여러 번 입력된 경우 한 번씩만 출력)
		if (i != n - 1) { 

			if (strcmp(arr[i], arr[i + 1]) == 0) { //두 단어가 동일한 단어일 경우
				//다음 인덱스로 스킵
			}
			else {
				printf("%s\n", arr[i]); //출력
			}
		} 
		else { //i = n-1 일 경우
			printf("%s\n", arr[i]); //출력
		}

	}

	//(6) 동적할당 해제
	free(arr);// <설명> 이중포인터이므로 arr[0], arr[1], arr[2]..일일이 해줄 필요x

	return 0;
}
