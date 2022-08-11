#!/bin/bash
##---------------SLURM Parameters - NLHPC ----------------
#SBATCH -J ejercicio5
#SBATCH -p gpus
#SBATCH -n 1
#SBATCH --gres=gpu:1
#SBATCH -c 1
#SBATCH --mem-per-cpu=2400
#SBATCH --mail-user=foo@bar.com 
#SBATCH --mail-type=ALL
#SBATCH -o ejercicio5_%j.out
#SBATCH -e ejercicio5_%j.err

ml purge
ml fosscuda/2019b

./mulBy2
