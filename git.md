# Git Commands — Project Repository

Repository: **Autonomous Logistics and Supply Chain Simulation**

## 🔄 Update the GitHub Repository

Whenever you make changes to the project:

```bash
git add .
git commit -m "Describe your changes"
git push
```

### Example

If you added the `Product` class:

```bash
git add .
git commit -m "Added Product class"
git push
```

If you added the vehicle hierarchy:

```bash
git add .
git commit -m "Added Vehicle, Bike, Van and Truck classes"
git push
```

---

## 🔍 Check Changes Before Committing

```bash
git status
```

Then:

```bash
git add .
git status
git commit -m "Updated project"
git push
```

---

## 🆕 First-Time Repository Setup

Only use these commands when setting up the repository for the first time:

```bash
git init
git branch -M main
git remote add origin https://github.com/Smoothoperator25/Autonomous-Logistics-and-Supply-Chain-Simulation.git
git add .
git commit -m "Initial project setup"
git push -u origin main
```

> **Do not run the setup commands every time you update the project.**

---

## 📌 Check Remote Repository

To check which GitHub repository is connected:

```bash
git remote -v
```

Expected output:

```text
origin  https://github.com/Smoothoperator25/Autonomous-Logistics-and-Supply-Chain-Simulation.git (fetch)
origin  https://github.com/Smoothoperator25/Autonomous-Logistics-and-Supply-Chain-Simulation.git (push)
```

---

## 📝 Useful Commit Messages

### Project structure

```bash
git commit -m "Updated project structure"
```

### New class

```bash
git commit -m "Added Product class"
```

### Multiple classes

```bash
git commit -m "Added Supplier and Warehouse classes"
```

### Vehicle system

```bash
git commit -m "Added Vehicle hierarchy"
```

### Bug fixes

```bash
git commit -m "Fixed inventory management"
```

### Documentation

```bash
git commit -m "Updated project documentation"
```

---

## ⚡ Quick Update

The only commands you normally need are:

```bash
git add .
git commit -m "Updated project"
git push
```

That's it.

## 🚫 Don't Repeat These

After the repository is connected, you normally **do not** need to run:

```bash
git init
git remote add origin ...
git branch -M main
git push -u origin main
```

Those are primarily for the initial setup.

---

## 🔄 Complete Workflow

```text
Make changes to code
        ↓
    git status
        ↓
     git add .
        ↓
git commit -m "Description"
        ↓
      git push
        ↓
   GitHub updated
```
