# 1) Considere uma tarefa que pode ser dividida em sub-tarefas com durações de 15, 25, 30
# e 20 segundos, respectivamente. Cada sub-tarefa é executada por um módulo
# especializado, e a execução é feita em modo pipeline.

# (a) Qual é o tempo de ciclo mínimo para o pipeline?

# (b) Supondo que existam 100 tarefas a executar, qual o speedup em relação à
# execução num modo estritamente serial?
print(100*(15+25+30+20))

# (c) Caso seja possível subdividir uma das sub-tarefas em duas novas sub-tarefas de
# igual duração, associando um módulo para a execução de cada uma, qual das
# sub-tarefas deve ser escolhida para divisão?
#Resposta A subtarefa de maior valor, no caso a subtarefa 3, que quando dividida geraria duas sub 
# tarefas com duaração de 15, diminuindo assim a bolha presente na execução

# (d) Após a divisão proposta no ítem anterior, qual o novo speedup possível em
# relação à execução estritamente serial das 100 tarefas?
