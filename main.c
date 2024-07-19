/*=== puzmon0: ソースコードひな形 ===*/
/*** インクルード宣言 ***/

#include <stdio.h>
#include <string.h>

/*** 列挙型宣言 ***/
typedef enum Element { FIRE, WATER, WIND, EARTH, LIFE, EMPTY } Element;

/*** グローバル定数の宣言 ***/

/*** 構造体型宣言 ***/
typedef struct player_monster {
  char name[32];
  int hp;
  int max_hp;
  Element element;
  int attack;
  int defense;
} PlayerMonster;

typedef struct enemy_monster {
  char name[32];
  int hp;
  int max_hp;
  Element element;
  int attack;
  int defense;
} EnemyMonster;

typedef struct party {
  char player_name[32];
  PlayerMonster *monsters[4];
  int hp;
  int max_hp;
  int defense;
  int num_killed_monsters;
} Party;

/*** プロトタイプ宣言 ***/
void doBattle(Party *party, EnemyMonster *enemy);
void goDungeon(Party *party);

/*** 関数宣言 ***/

int main(int argc, char **argv) {
  printf("*** Puzzle & Monsters ***\n");
  if (argc < 2) {
    printf("プレイヤー名を指定して起動してください\n");
    return 1;
  }
  Party party = {"", {NULL, NULL, NULL, NULL}, 100, 100, 20, 0};
  strncpy(party.player_name, argv[1], sizeof(party.player_name));

  goDungeon(&party);

  return 0;
}

void doBattle(Party *party, EnemyMonster *enemy) {
  printf("%sが現れた！\n", enemy->name);
  printf("%sを倒した！\n", enemy->name);
  party->num_killed_monsters++;
}

void goDungeon(Party *party) {
  if (party == NULL) {
    return;
  }
  printf("%sはダンジョンに到着した\n", party->player_name);

  EnemyMonster slime = {"スライム", 100, 100, WATER, 10, 5};
  EnemyMonster goblin = {"ゴブリン", 200, 200, EARTH, 20, 15};
  EnemyMonster fruit_bat = {"オオコウモリ", 300, 300, WIND, 30, 25};
  EnemyMonster werewolf = {"ウェアウルフ", 400, 400, WIND, 40, 30};
  EnemyMonster dragon = {"ドラゴン", 800, 800, FIRE, 50, 40};

  doBattle(party, &slime);
  doBattle(party, &goblin);
  doBattle(party, &fruit_bat);
  doBattle(party, &werewolf);
  doBattle(party, &dragon);

  printf("%sはダンジョンを制覇した！\n", party->player_name);
}

/*** ユーティリティ関数宣言 ***/
