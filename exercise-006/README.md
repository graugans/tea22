# Aufgabenstellung

## Git commands

```sh
git remote add upstream https://github.com/graugans/tea22.git
git fetch --all
git switch -c solution-006 upstream/main 
git push -u origin solution-006
```

## Verkette Liste

Implementieren Sie die verkettete Liste aus dem Skript

```cpp
typedef struct List {
    struct ListNode_t* pHead;
    struct ListNode_t* pTail;
    unsigned int size;
} List_t;
```

Die Struktur Listen-Knoten ist wie folgt definiert:

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;
```

Zu implementieren sind die folgenden Funktionalitäten:

- Einfügen in die Liste an beliebiger Stelle
- Löschen eines Elementes aus der Liste
- Iterieren der Liste, das heißt die Liste wird durchlaufen.
- Erstellen eines Listenelements
- Löschen eines Listenelements

Beachten Sie die sonderform der leeren Liste.

## Lernziele

- Vertiefung der git Kenntnisse
- Hinzufügen eines neuen Projektes in CMake
- Umgang mit der ``{fmt}`` Bibliothek
- Vertiefung der Funktionen `malloc` und `free`
- Bestimmung der unterschiedlichen Speichersegmente in einer ausführbaren Datei
