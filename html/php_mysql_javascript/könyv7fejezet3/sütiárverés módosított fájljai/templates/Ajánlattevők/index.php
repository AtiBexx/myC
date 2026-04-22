<?php
/**
 * @var \App\View\AppView $this
 * @var \App\Model\Entity\Ajánlattevők[]|\Cake\Collection\CollectionInterface $ajánlattevők
 */
?>
<div class="ajánlattevők index content">
    <?= $this->Html->link(__('New Ajánlattevők'), ['action' => 'add'], ['class' => 'button float-right']) ?>
    <h3><?= __('Ajánlattevők') ?></h3>
    <div class="table-responsive">
        <table>
            <thead>
                <tr>
                    <th><?= $this->Paginator->sort('ajánlattevőazonosító') ?></th>
                    <th><?= $this->Paginator->sort('vezetéknév') ?></th>
                    <th><?= $this->Paginator->sort('keresztnév') ?></th>
                    <th><?= $this->Paginator->sort('cím') ?></th>
                    <th><?= $this->Paginator->sort('telefon') ?></th>
                    <th class="actions"><?= __('Actions') ?></th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($ajánlattevők as $ajánlattevők): ?>
                <tr>
                    <td><?= $this->Number->format($ajánlattevők->ajánlattevőazonosító) ?></td>
                    <td><?= h($ajánlattevők->vezetéknév) ?></td>
                    <td><?= h($ajánlattevők->keresztnév) ?></td>
                    <td><?= h($ajánlattevők->cím) ?></td>
                    <td><?= h($ajánlattevők->telefon) ?></td>
                    <td class="actions">
                        <?= $this->Html->link(__('View'), ['action' => 'view', $ajánlattevők->ajánlattevőazonosító]) ?>
                        <?= $this->Html->link(__('Edit'), ['action' => 'edit', $ajánlattevők->ajánlattevőazonosító]) ?>
						<?= $this->Html->link(__('Tételek'), ['controller' => 'tételek','action' => 'megnyertTételekListázása', $ajánlattevők->ajánlattevőazonosító]) ?>
                        <?= $this->Form->postLink(__('Delete'), ['action' => 'delete', $ajánlattevők->ajánlattevőazonosító], ['confirm' => __('Are you sure you want to delete # {0}?', $ajánlattevők->ajánlattevőazonosító)]) ?>
                    </td>
                </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>
    <div class="paginator">
        <ul class="pagination">
            <?= $this->Paginator->first('<< ' . __('first')) ?>
            <?= $this->Paginator->prev('< ' . __('previous')) ?>
            <?= $this->Paginator->numbers() ?>
            <?= $this->Paginator->next(__('next') . ' >') ?>
            <?= $this->Paginator->last(__('last') . ' >>') ?>
        </ul>
        <p><?= $this->Paginator->counter(__('Page {{page}} of {{pages}}, showing {{current}} record(s) out of {{count}} total')) ?></p>
    </div>
</div>
