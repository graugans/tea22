# Aufgabenstellung

## Git commands

```sh
git remote -v
origin  https://github.com/IhrBenutzerName/tea22 (fetch)
origin  https://github.com/IhrBenutzerName/tea22 (push)
upstream        https://github.com/graugans/tea22.git (fetch)
upstream        https://github.com/graugans/tea22.git (push)

git fetch --all
git switch -c solution-002 upstream/excercise-002 
git push -u origin solution-002 
```

Falls der Upstream auf das falsche Repository zeigt:

```sh
git remote remove upstream 
git remote add upstream https://github.com/graugans/tea22.git
git fetch --all
git switch -c solution-002 upstream/excercise-002 
git push -u origin solution-002
```

## Die Zuordnung der Variablen in Segmente

In dieser gemeinsam bearbeiteten Übungsaufgabe wollen wir uns mit den verschiedenen Speichersegmenten beschäftigen.

## Lernziele

- Vertiefung der git Kenntnisse
- Hinzufügen eines neuen Projektes in CMake
- Umgang mit der ``{fmt}`` Bibliothek
- Bestimmung der unterschiedlichen Speichersegmente in einer ausführbaren Datei
