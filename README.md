
<div align="center">

<H1>COURSE PROJECT</H1>
<H3>TELECOMUNICATION THEORY<H3>

</div>

![Language][langue-shield]
![Course][course-shield]
![School][school-shield]
---

In this program we study a source data on which we will apply encoding/decoding and other calculation using
the following list of parameters:

| Symbol duration ns | Symbol to Noise Ration, dB | Source Code  | Error Correction Code | Error correction code parameters | Carrier Frequency, GHz | Modulation |
|:------------------:|:--------------------------:|:------------:|:---------------------:|:--------------------------------:|:----------------------:|:----------:| 
|         10         |            8.9             | Shannon-Fano | Group, non-systematic |              m = 27              |          1.0           |    BASK    |

---

The source given is the following:

|Source No. 4|
|:----------:|

| Sym.     | Prob. |
|----------|-------|
| a<sub>1  | 0.18  |
| a<sub>2  | 0.02  |
| a<sub>3  | 0.02  |
| a<sub>4  | 0.13  |
| a<sub>5  | 0.07  |
| a<sub>6  | 0.17  |
| a<sub>7  | 0.01  |
| a<sub>8  | 0.2   |
| a<sub>9  | 0.02  |
| a<sub>10 | 0.18  |

--- 

## Structure

├── main.cpp                 
└── data_source.h

## data_source.h

- [x] Source entropy
- [x] Maximum possible value
- [x] Source redundancy
- [x] Average code length
- [x] Probability of "0" and "1" symbol
- [] Binary entropy
- [] Source data generation rate
- [] Compression ratio
- [] Channel capacity without noise
- [] Bit Error Rate (BER)
- [] Channel Capacity with noise



<!-- MARKDOWN LINKS & IMAGES -->
[langue-shield]: https://img.shields.io/badge/Language-C++-lightblue.svg?style=for-the-badge&logo=c%2B%2B
[course-shield]: https://img.shields.io/badge/Course-Telecomunications_Theory-blue.svg?style=for-the-badge&logo=GitBook
[school-shield]:https://img.shields.io/badge/School-RTU-midnightblue.svg?style=for-the-badge&logo=GoogleScholar