import loader
import torch
import torch.nn as nn
import torch.nn.functional as F

device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')

tl = loader.TrainLoader()
data = torch.tensor(tl.data).to(device)
label = torch.tensor(tl.label).to(device)

test_data = torch.tensor(tl.data[800:]).to(device)
test_label = torch.tensor(tl.label[800:]).to(device)

class Network(nn.Module):
    def __init__(self):
        super(Network, self).__init__()
        self.layer1 = nn.Linear(7, 35)
        self.out = nn.Linear(35, 2)

    def forward(self, x):
        o1 = F.relu(self.layer1(x))
        return F.softmax(self.out(o1), dim=1)

net = Network().to(device)
print(net)

optimizer = torch.optim.Adam(net.parameters(), lr=0.05)
loss_func = nn.CrossEntropyLoss()

for i in range(50000):
    out = net(data.float())
    loss = loss_func(out, label)
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

_, l = torch.max(net(test_data.float()), 1)
correct = 0
print(l)
for i in range(len(l)):
    if l[i] == test_label[i]:
        correct += 1
print('correct rate %f'%(correct / len(l)))
torch.save(net.state_dict(), 'network.pt')

