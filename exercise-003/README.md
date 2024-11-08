# Aufgabenstellung

## Git commands

Um die Aufgabe 3 in Ihr Repository zu übertragen führen Sie bitte die folgenden Befehle aus:
Zuerst prüfen wir ob die remotes stimmen!

```sh
git remote -v
origin  https://github.com/IhrBenutzerName/tea22 (fetch)
origin  https://github.com/IhrBenutzerName/tea22 (push)
upstream        https://github.com/graugans/tea22.git (fetch)
upstream        https://github.com/graugans/tea22.git (push)
```

Anschließend erstellen Sie einen Branch für die Lösung.

```sh
git fetch --all
git switch -c solution-003 upstream/excercise-003 
git push -u origin solution-003
```

## Unser erstes C/C++ Modul

In dieser gemeinsam bearbeiteten Übungsaufgabe wollen wir uns weiter mit den verschiedenen Speichersegmenten beschäftigen, sowie eine Übersetzungseinheit einführen. Dazu habe ich die Funktionen und Variablen aus der zweiten Übungsaufgabe in das Modul und dessen Header verschoben.

## Lernziele

- Vertiefung der git Kenntnisse
- Hinzufügen eines neuen Projektes in CMake
- Umgang mit der ``{fmt}`` Bibliothek
- Bestimmung der unterschiedlichen Speichersegmente in einer ausführbaren Datei
- Verwendung des Schlüsselwortes ``static`` innerhalb eines Moduls.
