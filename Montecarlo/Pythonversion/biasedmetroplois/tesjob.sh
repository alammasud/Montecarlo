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

python swapatom.py 

/u/alam/bin/lammps-10Feb15/src/lmp_cmmc <input.txt

#if ! (($aaid % 1000)) ;then
#grep Loop log -B1|grep -v Loop|awk '7' >> energy
#fi
grep Loop log -B1|grep -v Loop|awk '7' >> everyenergy

python readump.py

#cp pl2 pl


#if ! (($aaid % 10000)) ;then
#cp datafileswap datafile.$aaid
#fi

done
python biasmc.py
done

