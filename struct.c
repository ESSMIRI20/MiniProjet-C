#include <stdio.h>
#include <stdlib.h>

struct Eleve {
    char nom[50];
    char prenom[50];
    int age;
    float notes[3];
};

float moyenne(struct Eleve eleve) {
    float somme = 0.0;
    for (int i = 0; i < 3; i++) {
        somme += eleve.notes[i];
    }
    return somme / 3;
}

int main() {
    
    int n;
    printf("entrer le numero d'etudiants : ");
    scanf("%d", &n);

    struct Eleve m[n];
    printf("entrer les informations :\n");

    for (int j = 0; j < n; j++) {
         printf("etudiant N%d~\n",j+1);
        printf("Entrer le nom : ");
        scanf("%s", m[j].nom);
        printf("Entrer le prenom : ");
        scanf("%s", m[j].prenom);
        printf("Entrer l'age : ");
        scanf("%d", &m[j].age);
        printf("Entrer les notes :\n");
        for (int i = 0; i < 3; i++) {
            printf("Entrer la note %d : ", i+1);
            scanf("%f", &m[j].notes[i]);
        }
    }

    int k = 0;
    float max = moyenne(m[0]);
    for (int i = 1; i < n; i++) {
        if (max < moyenne(m[i])){
            max = moyenne(m[i]);
            k = i;
        }
    }
    printf("Nom : %s, Prenom : %s, Age : %d, Moyenne : %.2f\n", m[k].nom, m[k].prenom, m[k].age, max);

    return 0;
}
