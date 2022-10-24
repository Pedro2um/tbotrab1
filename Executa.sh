make
clear

./trab1 ./exemplos/in/a280.tsp
./trab1 ./exemplos/in/berlin52.tsp
./trab1 ./exemplos/in/d18512.tsp
./trab1 ./exemplos/in/eil101.tsp
./trab1 ./exemplos/in/pr1002.tsp
./trab1 ./exemplos/in/tsp225.tsp

echo "a280"
python3 ./exemplos/tsp_plot.py ./exemplos/in/a280.tsp ./exemplos/mst/a280.mst ./exemplos/tour/a280.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/a280.tsp ./saidas/a280.mst ./saidas/a280.tour

echo -e "\nberlin52"
python3 ./exemplos/tsp_plot.py ./exemplos/in/berlin52.tsp ./exemplos/mst/berlin52.mst ./exemplos/tour/berlin52.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/berlin52.tsp ./saidas/berlin52.mst ./saidas/berlin52.tour

echo -e "\nd18512"
python3 ./exemplos/tsp_plot.py ./exemplos/in/d18512.tsp ./exemplos/mst/d18512.mst ./exemplos/tour/d18512.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/d18512.tsp ./saidas/d18512.mst ./saidas/d18512.tour

echo -e "\neil101"
python3 ./exemplos/tsp_plot.py ./exemplos/in/eil101.tsp ./exemplos/mst/eil101.mst ./exemplos/tour/eil101.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/eil101.tsp ./saidas/eil101.mst ./saidas/eil101.tour

echo -e "\npr1002"
python3 ./exemplos/tsp_plot.py ./exemplos/in/pr1002.tsp ./exemplos/mst/pr1002.mst ./exemplos/tour/pr1002.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/pr1002.tsp ./saidas/pr1002.mst ./saidas/pr1002.tour

echo -e "\ntsp225"
python3 ./exemplos/tsp_plot.py ./exemplos/in/tsp225.tsp ./exemplos/mst/tsp225.mst ./exemplos/tour/tsp225.tour
python3 ./exemplos/tsp_plot.py ./exemplos/in/tsp225.tsp ./saidas/tsp225.mst ./saidas/tsp225.tour