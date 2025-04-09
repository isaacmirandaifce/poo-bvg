from django import template

register = template.Library()

@register.filter
def replace(value, args):
    try:
        old, new = args.split(',')
        return value.replace(old, new)
    except ValueError:
        return value 