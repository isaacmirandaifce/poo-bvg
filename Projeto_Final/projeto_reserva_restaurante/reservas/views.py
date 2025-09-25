from django.shortcuts import render, redirect
from .models import Mesa, Reserva
from .forms import ReservaForm

def criar_reserva(request):
    if request.method == 'POST':
        form = ReservaForm(request.POST)
        if form.is_valid():
            dados = form.cleaned_data
            mesas_reservadas_ids = Reserva.objects.filter(data=dados['data']).values_list('mesa_id', flat=True)
            mesa_disponivel = Mesa.objects.filter(
                capacidade__gte=dados['quantidade_pessoas']
            ).exclude(id__in=mesas_reservadas_ids).first()
            if mesa_disponivel:
                reserva = form.save(commit=False)
                reserva.mesa = mesa_disponivel
                reserva.save()
                return redirect('sucesso_reserva')
            else:
                form.add_error(None, "Nenhuma mesa disponível para esta data/quantidade.")
    else:
        form = ReservaForm()

    contexto = {'form': form}
    return render(request, 'reservas/form_reserva.html', contexto)

def sucesso_reserva(request):
    ultima_reserva = Reserva.objects.last()
    contexto = {'reserva': ultima_reserva}
    return render(request, 'reservas/sucesso.html', contexto)
