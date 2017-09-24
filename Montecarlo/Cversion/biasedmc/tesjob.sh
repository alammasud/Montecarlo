#$ -S /bin/bash
#$ -j y
#$ -cwd
#$ -m n
#$ -N t400.0
#$ -l h_rt=100:00:00
#$ -pe impi_hydr* 2
date
ulimit -aH
module load impi
module load lammps

#rm t400.*

here=$(pwd)

gcc lattice.c -o lattice
./lattice >out

declare -a kk=( $(<out))
for kk in ${kk[@]};do
  kkid=${kk[$idx]}
rm testdata
declare -a arr=( $(<out1))


for arr in ${arr[@]};do
    aaid=${arr[$idx]}
gcc createparent.c  -o createparent  -lm
./createparent

/u/alam/bin/lammps-10Feb15/src/lmp_cmmc <input.txt

#if ! (($aaid % 1000)) ;then
#grep Loop log -B1|grep -v Loop|awk '7' >> energy
#fi
grep Loop log -B1|grep -v Loop|awk '7' >> everyenergy

gcc dump1.c -o dump1  -lm
./dump1 >>testdata

#cp pl2 pl


#if ! (($aaid % 10000)) ;then
#cp datafileswap datafile.$aaid
#fi

done
gcc biasedmc.c -o biasedmc -lm
./biasedmc
done

