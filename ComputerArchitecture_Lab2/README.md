<p align="center"><img src="https://arch.cs.ucdavis.edu/assets/images/gem5-logo.png" alt="Gem5-logo" width="250"/></p>

# Εργασία Δεύτερου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών

**Παπακωνσταντίνου Αντώνης, ΑΕΜ 8977**

**Κασιούλης Φίλιππος, ΑΕΜ 8966**

## Ερωτήματα Δεύτερου Μέρους

### **Βήμα 1°.** Εκτέλεση CPEC CPU2006 Benchmarks στον GEM5:

Στο βήμα αυτό αφού κατεβάσαμε τα απαραίτητα benchmarks, κάναμε Compile κάθε ένα χρησιμοποιώντας την εντόλη `make` και τρέξαμε τις εντολές που μας δόθηκαν.

- **Ερώτημα 1.1.** Στο ερώτημα αυτό εξετάσαμε τα αρχεία `config.ini` από κάθε benchmark (*401.bzip2, 429.mcf, 456.hmmer, 458.sjeng, 470.lbm*) και βρήκαμε τις βασικές παραμέτρους για τον επεξεργαστή που εξομοιώνει ο gem5 όσον αφορά το υποσύστημα μνήμης:

1. L1I size (Instruction): 

> [system.cpu.icache]: size = 32768 Bytes

2. L1D size (Data Caches): 

> [system.cpu.dcache]: size = 65536 Bytes

3. L2 size: 

> [system.l2]: size = 2097152 Bytes

4. L1I associativity:

> [system.cpu.icache]: assoc = 2

5. L1D associativity:

> [system.cpu.dcache]: assoc = 2

6. L2 associativity:

> [system.l2]: assoc = 8

7. Cache line size:

> [system]: cache_line_size = 64 Bytes

- **Ερώτημα 1.2.** Στο δεύτερο ερώτημα του πρώτου βήματος, εξετάσαμε αυτήν την φορά τα αρχεία `stats.txt` από κάθε benchmark και συλλέξαμε τις απαραίτητες πληροφορίες για τον **χρόνο εκτέλεσης** (sim seconds) κάθε benchmark, το **CPI** (Cycles Per Instruction) και τα **Total Miss Rates** για τα **L1I, L1D, L2 cache** και τα παραθέτουμε στα παρακάτω γραφήματα.


1. Simulation Time:

![Sim_Seconds](https://github.com/tonypapakon/ComputerArchitecture_Lab2/blob/master/GRAPHS/Simulation%20Seconds.jpeg)

2. CPI:

![CPI](https://github.com/tonypapakon/ComputerArchitecture_Lab2/blob/master/GRAPHS/CPI.jpeg)

3. Total Miss Rate L1 Data cache:

![TMR_L1D](https://github.com/tonypapakon/ComputerArchitecture_Lab2/blob/master/GRAPHS/Total%20Miss%20Rate%20L1D.jpeg)

4. Total Miss Rate L1 Instruction cache:

![TMR_L1I](https://github.com/tonypapakon/ComputerArchitecture_Lab2/blob/master/GRAPHS/Total%20Miss%20Rate%20L1I.jpeg)

5. Total Miss Rate L2 cache:

![TMR_L2](https://github.com/tonypapakon/ComputerArchitecture_Lab2/blob/master/GRAPHS/Total%20Miss%20Rate%20L2.jpeg)

Παρατηρούμε από τα διαγράμματα ότι για κάθε *benchmark* το **Simulation Time** είναι ανάλογο με το **CPI**, αυτό συμβαίνει γιατί κάθε εξομοίωση έτρεξε ίδιο αριθμό εντολών. Επίσης, παρατηρούμε ότι το *458.sjeng* είναι το πιο αργό και έχει πολύ υψηλό **CPI** σε σχέση με τα άλλα *benchmarks*, ενώ το *429.mcf* είναι το πιο γρήγορο απ'όλα με το *456.hmmer* να ακολουθεί με πάρα πολύ μικρή διαφορά. Εξετάζοντας τα **Total Miss Rates** και συγκεκριμένα τα **L1D** και **L2** βλέπουμε τον λόγο που συμβαίνει αυτό στο *458.sjeng*, έχει πάρα πολύ υψηλά επίπεδα αστοχίας σε σχέση με τα άλλα *benchmarks*, που σημαίνει ότι πρέπει να κάνει περισσότερη ώρα ο επεξεργραστής για να βρει την πληροφορία που ζητάει. 
 
- **Ερώτημα 1.3.** Στο ερώτημα αυτό τρέξαμε την εντολή που μας δόθηκε με την παράμετρο `--cpu-clock=1GHz`.

Από τα αρχεία `stats.txt` πήραμε για κάθε συχνότητα επεξεργαστή (1GHz & 2GHz) όλων των benchmarks τις τιμές των **sim_seconds** και τις παραθέτουμε στον παρακάτω πίνακα μαζί με τα **scaling** τους.

| CPU - Clock | 401.bzip2 | 429.mcf | 456.hmmer | 458.sjeng | 470.lbm |
|---|---|---|---|---|---|
| 1 GHz | 0.161337 | 0.109125 | 0.118453 | 0.704063 | 0.262355 |
| 2 GHz | 0.084159 | 0.055477 | 0.059368 | 0.513541 | 0.174681 |
| Scaling | 1.917 | 1.967 | 1.995 | 1.371 | 1.502 |

Παρατηρούμε ότι το **scaling** για τα benchmarks: **401.bzip2, 429.mcf, 456.hmmer** είναι **σχεδόν** καθαρά διπλάσιο (x2) στις δυο συχνότητες. Aυτό σημβαίνει γιατί όπως είδαμε στο παραπάνω ερώτημα από τα διαγράμματα, το **TotalMissRate** στην **L2** έχει ελάχιστες περιπτώσεις που δεν καλύπτεται από το σύστημα μας και αναγκάζεται να καταφύγει στα κατώτερα επίπεδα μνήμης. Αντίστοιχα μπορούμε να δούμε για τα benchmarks: **458.sjeng, 470.lbm** ότι λόγω του αυξημένου **TotalMissRate** στην **L2** καταφεύγουμε σε σύστημα εκτός του επεξεργαστή τις περισσότερες φορές, γι'αυτό και έχουμε ελαττωμένο **scaling** ~1.4 και ~1.5. 

### **Βήμα 2°.** Design Exploration - Βελτιστοποίηση απόδοσης:

- **Ερώτημα 2.1.** Σ'αυτό το ερώτημα θα εξετάσουμε τα αποτελέσματα που υπάρχουν αποθηκευμένα στο `stats.txt` από το **Βήμα 1°.** για κάθε *benchmark* και θα προσπαθήσουμε να βρούμε τροπους να πετύχουμε την **μέγιστη απόδοση** του συστήματος.

#### i. 401.bzip2

| CPI | T.MissRateL1D | L1D Accesses | T.MissRateL1I | L1I Accesses | T.MissRateL2 | L2 Accesses |
|---|---|---|---|---|---|---|
|	1.683172 |	0.014840 |	52164486 |	0.000074 |	10198809 |	0.281708 |	714016 |

Για να έχουμε βελτίωση αυτού του benchmark θα πρέπει να **βελτιώσουμε** πρώτα την **L1D** και μέτα την **L2**. Αυτό προκύπτει απ'το γεγονός ότι η L1I δεν έχει πρόβλημα καθώς το TotalMissRate της είναι χαμηλό και τα Accesses της είναι το 1/5 των Accesses της L1D. Η L1D αντιθέτος έχει αρκετά μεγάλο TotalMissRate και πολλά Accesses. Όσο αναφορά την L2 αν και το TotalMissRate της είναι το πιο μεγάλο από τις άλλες δύο μνήμες, ο αριθμός των Accesses είναι μίκρος και ξέρουμε ότι ισχύει `Misses = TotalMissRate x Accesses` και επειδή η L2 είναι αρκετά πιο ακριβή μνήμη από την L1 πρεπεί να επικεντροθούμε πρώτα στην L1D και μέτα στην L2.

#### ii. 429.mcf

| CPI | T.MissRateL1D | L1D Accesses | T.MissRateL1I | L1I Accesses | T.MissRateL2 | L2 Accesses |
|---|---|---|---|---|---|---|
| 1.109538 |	0.002051 |	35173755 |	0.000037 |	27009248 |	0.724040 |	53631 |

Για να έχουμε βελτιώση αυτού του benchmark θα πρέπει να **βελτιώσουμε** πρώτα την **L1D** και μετά την **L2**. Αυτό προκύπτει απ'το γεγονός ότι όπως και το **401.bzip2** έχει χαμηλό MissRate στην L1I αλλά ελαφρός αυξημένα Accesses. Η L1D σε σχέση με την L1I έχει μεγαλύτερο MissRate και αριθμό Accesses, άρα η L1D έχει προτεραιότητα στην βελτίωση. H μνήμη L2 έχει πολύ μεγάλο ποσοστό MissRate επομένος θέλει και αυτή βελτίωση.   

#### iii. 456.hmmer

| CPI | T.MissRateL1D | L1D Accesses | T.MissRateL1I | L1I Accesses | T.MissRateL2 | L2 Accesses |
|---|---|---|---|---|---|---|
|	1.184534	| 0.001638 |	43865013 |	0.000205 |	17142384 |	0.082233 |	70495 |

Για να έχουμε βελτιώση αυτού του benchmark θα πρέπει να **βελτιώσουμε** την **L1D**. Αυτό προκύπτει απ'το γεγονός ότι όπως και στο παραπάνω benchmark η L1I έχει πολύ χαμηλότερο αριθμό Accesses και TotalMissRate σε σχέση με την L1D, άρα απ'τις δυο περισσότερο ανάγκη για βελτίωση έχει η L1D. Στην L2 παρατηρούμε σχετικά χαμηλό MissRate σε σχέση με τα άλλα benchmarks και ένα μικρό ποσό Accesses άρα υποθέτουμε ότι δεν χρήζει την άμεση βελτίωση όπως στα άλλα benchmarks.  

#### iv. 458.sjeng

| CPI | T.MissRateL1D | L1D Accesses | T.MissRateL1I | L1I Accesses | T.MissRateL2 | L2 Accesses |
|---|---|---|---|---|---|---|
| 10.270810 |	0.121829 |	86382246 |	0.000020 |	31871080 |	0.999979 |	5263951 |

Για να έχουμε βελτιώση αυτού του benchmark θα πρέπει να **βελτιώσουμε** πρώτα την **L1D** και μετά την **L2**. Αυτό προκύπτει απ'το γεγονός ότι έχουμε ένα πολύ αυξημένο MissRate στην L1D και ένα τεράστιο αριθμό Accesses. Απ'την άλλη ενώ η μνήμη L1I έχει ένα πολύ καλό MissRate ο αριθμός των Accesses της είναι πάρα πολύ μεγάλος και αυτής αλλά δεν είναι άμεσα αναγκαίο να την βελτιώσουμε. Τέλος και σε συνδιασμό με τα προηγούμενα βλέπουμε ενα MissRate στην L2 σχεδόν μονάδα και ένα πολύ μεγάλο αριθμό Accesses, γι'αυτό και παρατηρούμε το μεγαλύτερο **CPI** απ'όλα τα benchmarks και με μεγάλη διαφορά κι όλας.

#### v. 470.lbm

| CPI | T.MissRateL1D | L1D Accesses | T.MissRateL1I | L1I Accesses | T.MissRateL2 | L2 Accesses |
|---|---|---|---|---|---|---|
|	2.623555 |	0.060971 |	48806502 |	0.000099 |	5959251 |	0.999927 |	1488551 |

Για να έχουμε βελτιώση αυτού του benchmark θα πρέπει να **βελτιώσουμε** πρώτα την **L1D** και μετά την **L2**. Γενικά παρατηρήσαμε μια παρόμοια συμπεριφορά με αυτή του **458.sjeng** benchmark με μια μικρή βελτίωση στο MissRate της L1D καθώς και στον αριθμό Accesses της άλλα παραμένει αρκετά υψηλός και γι'αυτό θεωρούμε ότι χρήζει βελτίωση η συγκεκριμένη μνήμη. Επίσης βελτίωση είδαμε και στα Accesses της L1I με μια πολύ μικρή άνοδο του MissRate της που δεν προκαλεί κάποια αρνητική συμπεριφορά. Τέλος η μνήμη L2 είδε και αυτή μια βελτίωση στον αριθμό Accesses αλλά εξακολουθεί να είναι πολύ μεγάλος, το MissRate της παρέμεινε σταθερά σχεδόν μονάδα. Ενώ ύπαρχει κάποια βετλίωση σε σχέση με το 458.sjeng δεν είναι πολύ αισθητή και γι'αυτό το CPI του 470.lbm είναι το δεύτερο μεγαλύτερο από τα benchmarks που μας δόθηκαν να μελετήσουμε.

- **Ερώτημα 2.2.**

Στο ερώτημα αυτό τρέξαμε πάλι κάθε benchmark που μας δόθηκε πειράζοντας κάθε φορά την παράμετρο για την μνήμη cache του εξομοιωτή. Πήραμε τα εξής διαγράμματα:

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L1ICacheSize.png)

1. L1I Cache Size: Απ'το διάγραμμα παρατηρούμε ότι μόνο το **429.mcf** επηρεάζεται απ'την αλλαγή του L1I Size και αιτιολογείται απ'το γεγονός ότι έχει αυξημένο αριθμό Accesses στην L1I.

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L1IAssociativity.png)

2. L1I Cache Associativity: Απ'το διάγραμμα παρατηρούμε ότι δεν υπάρχει ιδιαίτερη βελτίωση σε κανένα από τα benchmarks κάτι που το διαπιστώσαμε και σε προηγούμενο ερώτημα, ότι το L1I δεν επιρεάζει το CPI όπως το L1D και L2.

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L1DCacheSize.png)

3. L1D Cache Size: Απ'το διάγραμμα βλέπουμε ότι το **401.bzip2** έχει βελτίωση όσο αυξάνουμε το μέγεθος της μνήμης άρα παρατηρούμε ότι το benchmark αυτό έχει πολλά `capacity misses`, σε αντίθεση με τα υπόλοιπα benchmarks που δεν παρατηρούμε διαφορές στο CPI τους, άρα δεν υπάρχει σημαντικός αριθμός από `capacity misses`.

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L1DAssociativity.png)

4. L1D Cache Associativity: Απ'το διάγραμμα βλέπουμε ότι πάλι το **401.bzip2** έχει βελτίωση όσο αυξάνουμε το associativity του άρα παρατηρούμε ότι το benchmark αυτό έχει πολλά `conflict misses` κατί που και πάλι δεν ισχύει στα υπόλοιπα benchmarks.

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L2CacheSize.png)

5. L2 Cache Size: Απ'το διάγραμμα βλέπουμε ότι το **401.bzip2** έχει μια βελτίωση. Το **429.mcf** ενώ ξεκίνησε να έχει βελτίωση στην αρχή μετά έμεινε σταθερό. Στα υπόλοιπα benchmarks δεν παρατηρήθηκε καμία βελτίωση. 

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/L2Associativity.png)

6. L2 Cache Associativity: Απ'το διάγραμμα παρατηρούμε ότι και πάλι το **401.bzip2** έχει μια βελτίωση και πως ενώ το **429.mcf** ξεκίνησε με βελτίωση στην συνέχεια δεν παρατηρήθηκε τίποτα.

![](https://github.com/tonypapakon/ComputerArchitecture/blob/master/ComputerArchitecture_Lab2/GRAPHS/STEP2/CacheLineSize.png)

7. Cache Line Size: Απ'το διάγραμμα βλέπουμε ότι την μεγαλύτερη βελτίωση την είδε το **458.sjeng** και το **470.lbm** κάτι που μας δείχνει ότι έχουμε μεγάλο `locality`, μικρή αλλά σημαντική βελτίωση έδειξαν και τα **401.bzip2** και **429.mcf**. Τέλος δεν παρατηρήθηκε κάποια σημαντική βελτίωση στο **456.hmmer** επομένως δεν έχει καθόλου `locality`.

### **Βήμα 3°.** Κόστος απόδοσης και βελτιστοποίηση κόστους/απόδοσης:

- **Ερώτημα 3.**

Στο ερώτημα αυτό καλούμαστε να δημιουργήσουμε την εξίσωση του **Κόστους Απόδοσης**, για τον λόγω αυτό ψάξαμε να βρούμε την συσχέτιση μεταξύ του κόστους της μνήμης L1 και της L2.

Η εξίσωση του Κόστους είναι η εξής:

**Cost = L1ISize + L1IAssoc + L1DSize + L1DAssoc + L2Size + L2Assoc**
